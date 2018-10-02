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

INSTALL_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null && pwd)"

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

export TEST42F_DIR="$INSTALL_DIR/lib/test42f" # exported for makefile.
export SRC=`grep "$dir.*.c" .42framework | tr '\n' ' '` # exported for makefile.
export NAME="test_$dir"

print $Yellow "Testing $dir ========================================\n"
print $Cyan "Compiling handins sources...\n"

cd $dir
make
out=$?

if [ "$out" -ne 0 ]
then
	echo $out
	print $Red "Compilation unsuccessful. Exiting.\n"
	cd ..
	exit 1
fi
print $Green "Compilation succeed.\n"
cd ..
echo $sources | cat -e

	print $Cyan "Compiling tests sources...\n"

	cd tests/$dir
	make compile
	out=$?

	if [ "$out" -ne 0 ]
	then
		echo $out
		print $Red "Compilation unsuccessful. Exiting.\n"
		exit 1
	fi
	print $Green "Compilation succeed\n"
	print $Cyan "Running tests...\n"
	make test
	make clean
	cd ../..


if [ 0 -lt $# ] && [ "$1" = "--norm" ]
then

	print $Cyan "Checking norm...\n"
	norminette -R CheckForbiddenSourceHeader $dir/*.c 2> /dev/null
	norminette -R CheckForbiddenSourceHeader $dir/*.h 2> /dev/null
fi
print $Yellow "=====================================================\n"
exit 0
