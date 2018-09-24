#!/bin/sh

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Takes 2 params, first is a color, second is a string
# Does not print a new line
function print {
	printf "${1}${2}${Color_Off}"
}

if [ ! -f .42framework ]
then
	echo "You can only execute this script in a repo initialized with the 'init42' command."
	exit 1
fi

EX_NB=$1
shift

if [ $EX_NB -lt 10 ]
then
	dir="ex0$EX_NB"
else
	dir="ex$EX_NB"
fi

print $Purple "Testing $dir ========================================\n"
print $Cyan "Compiling source files...\n"
gcc -Wall -Wextra -Werror -o tests/test_$dir tests/test_$dir.c
out=$?

if [ "$out" -ne 0 ]
then
	echo $out
	print $Red "Compilation unsuccessful. Exiting.\n"
	exit 1
fi

print $Green "Compilation finished\n"
print $Cyan "Running tests...\n"

./tests/test_$dir
out=$?

if [ "$out" -ne 0 ]
then
	print $Red "Tests failed. Exiting\n"
	exit 1
fi

print $Green "Tests finished successfully.\n"

if [ 0 -lt $# ] && [ "$1" = "--norm" ]
then

	print $Cyan "Checking norm...\n"
	norminette -R CheckForbiddenSourceHeader $dir 2> /dev/null
fi
print $Purple "=====================================================\n"
exit 0
