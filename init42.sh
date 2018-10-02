#!/bin/sh

PDF_URL=$1
REPO_URL=$2
BASEDIR=$3
INSTALL_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

clone=`git clone $REPO_URL $BASEDIR`

if [ "$clone" == "*fatal:*" ]
then
	echo "Failed to clone git repo. Exiting"
	exit
else
	echo "Git repo cloned successfully."
fi

cd $BASEDIR
echo "# 42 framework settings, do not modify.\n" > .42framework
echo "**" > .gitignore
mkdir tests
mkdir doc

if [[ $PDF_URL =~ ^https?://. ]]
then
	curl $PDF_URL --output doc/instructions.pdf
else
	cp $PDF_URL doc/instructions.pdf
fi

$INSTALL_DIR/lib/xpdftools-4.0.0/bin64/pdftotext doc/instructions.pdf doc/instructions.txt
EXSTR=`grep "Turn-in directory" doc/instructions.txt | sed -n -e 's/^.*Turn-in directory : //p' | sed -e 's/ Allowed functions : .*//g' | sed -e 's/\/ Files to turn in : //g'`

IFS=$'\r\n' GLOBIGNORE='*' command eval 'exs=($EXSTR)'
for ex in "${exs[@]}"
do
	dir=`cut -c1-4 <<< $ex`
	files=`cut -c 5- <<< $ex | tr -d ' '`

	IFS=$'\r\n,' GLOBIGNORE='*' command eval 'filenames=($files)'
	
	if [ ! -d "$dir" ]
	then 
		mkdir $dir
	fi
	if [ ! -d  "tests/$dir" ] 
	then
		mkdir tests/$dir
	fi
	cp $INSTALL_DIR/templates/test_template.c tests/$dir/test_$dir.c
	cp $INSTALL_DIR/templates/Makefile_test tests/$dir/Makefile
	echo "$dir/**" >> .gitignore
	for filename in "${filenames[@]}"
	do
		if [ $filename != "Makefile" ]
		then
			cp $INSTALL_DIR/templates/Makefile_sources $dir/Makefile
		fi
		echo "!$dir/" >> .gitignore
		if [ $filename = "andyourprogramfiles" -o $filename = "Allnecessaryfiles" -o $filename = "andfilesneededforyourprogram" ]
		then
			echo "!$dir/*.c" >> .gitignore
			echo "!$dir/*.h" >> .gitignore
			echo "!$dir/Makefile" >> .gitignore
			echo "$(pwd)/$dir/*.c" >> .42framework
			echo "$(pwd)/$dir/*.h" >> .42framework
		else
			if [ ! -f "$dir/$filename" ]
			then
				vim -c Stdheader -c wq $dir/$filename
			fi
			echo "!$dir/$filename" >> .gitignore
			echo "$(pwd)/$dir/$filename" >> .42framework
		fi
		case "$filename" in
			*.h) vim -c '14i|#include "../'$dir'/'$filename'"' -c wq tests/test_$dir.c ;;
			*) ;;
		esac
	done
done
