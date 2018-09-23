#!/bin/sh

NB_EX=$1
REPO_URL=$2
BASEDIR=$3
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

while [ $i -lt $NB_EX ]
do
	
	if [ $i -lt 10 ]
	then
		dir="ex0$i"
	else
		dir="ex$i"
	fi

	mkdir $dir
	echo "#include <libc.h>\n#include <stdio.h>\n#include <stdlib.h>" > tests/test_$dir.c

	echo "Enter submission files for $dir separated by commas: \n"

	read subs
	IFS=', ' read -r -a sub_files <<< "$subs"
	for filename in "${sub_files[@]}"
	do
		touch $dir/$filename
		filepath="$(pwd)/$dir/$filename"
		echo $filepath >> .42framework
		echo "!$dir/" >> .gitignore
		echo "$dir/**" >> .gitignore
		echo "!$dir/$filename" >> .gitignore
		echo '#include "../'$dir'/'$filename'"' >> tests/test_$dir.c
	done
	echo "\nint\tmain(void)\n{\n\t/* Write your tests here and return 1 if something is wrong */\n\treturn (0);\n}" >> tests/test_$dir.c
	i=$(($i + 1))
done

exit

