#!/bin/sh

if [ ! -f .42framework ]
then
	echo "You can only execute this script in a repo initialized with the 'init42' command."
	exit 1
fi

EX_NB=$1
if [ $EX_NB -lt 10 ]
then
	dir="ex0$EX_NB"
else
	dir="ex$EX_NB"
fi

echo "Compiling source files..."
gcc -Wall -Wextra -Werror -o tests/test_$dir tests/test_$dir.c
out=$?

if [ "$out" -ne 0 ]
then
	echo $out
	echo "Compilation unsuccessful. Exiting."
	exit 1
fi

echo "Compilation finished"
echo "Running tests..."

./tests/test_$dir
out=$?

if [ "$out" -ne 0 ]
then
	echo "Tests failed. Exiting"
	exit 1
fi

echo "Tests finished successfully."
echo "Checking norm..."

out=`norminette -R CheckForbiddenSourceHeader $files 2> /dev/null`
if [ "$out" -eq "*Error*" ]
then
	echo $out
	echo "Norm checks failed. Exiting."
	exit 1
fi
exit 0
