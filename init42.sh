#!/bin/sh

PDF_URL=$1
REPO_URL=$2
BASEDIR=$3
INSTALL_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
i=0


clone=`git clone $REPO_URL $BASEDIR`

if [ "$clone" -neq "*fatal: *"]
then
	echo "Failed to clone git repo. Exiting"
else
	echo "Git repo cloned successfully."
fi

cd $BASEDIR
echo "# 42 framework settings, do not modify.\n" > .42framework
echo "**" > .gitignore
mkdir tests
mkdir doc

wget -O doc/instructions.pdf $PDF_URL
.$INSTALL_DIR/lib/xpdftools-4.0.0/bin64/pdftotext doc/instructions.pdf doc/instructions.txt
EXSTR=`grep "Turn-in directory" instructions.txt | sed -n -e 's/^.*Turn-in directory : //p' | sed -e 's/ Allowed functions : .*//g' | sed -e 's/\/ Files to turn in : //g'`
IFS='\n' read -r -a exs <<< "$EXSTR"

for ex in "${exs[@]}"
do
	dir=`cut -c1-4 $ex`
	files=`cut -c 4- $ex`

	IFS='\n' read -r -a filenames <<< "$files"
	
	mkdir $dir
	cp $INSTALL_DIR/lib/test_template.c tests/test_$dir
	echo "$dir/**" >> .gitignore
	
	for filename in "${filenames[@]}"
	do
		touch $dir/$filename
		filepath="$(pwd)/$dir/$filename"
		echo $filepath >> .42framework
		echo "!$dir/" >> .gitignore
		echo "!$dir/$filename" >> .gitignore
	done
done
