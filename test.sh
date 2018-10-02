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
SRC=`grep "$dir.*\.c" .42framework | tr '\n' ' '`
SRC=`eval echo $SRC` 
SRC=`echo $SRC | sed 's/[^ ]*[*][^ ]*//'` 
export SRC # exported for makefile.
export NAME="test_$dir"
SUBMIT=`grep "$dir" .42framework | tr '\n' ' '`
SUBMIT=`eval echo $SUBMIT`
SUBMIT=`echo $SUBMIT | sed 's/[^ ]*[*][^ ]*//'`

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

	print $Cyan "Compiling tests sources...\n"

	cd tests/$dir
	
	make
	out=$?

	if [ "$out" -ne 0 ]
	then
		echo $out
		print $Red "Compilation unsuccessful. Exiting.\n"
		exit 1
	fi
	print $Green "Compilation succeed\n"
	print $Cyan "Running tests...\n"
	export DYLD_FALLBACK_LIBRARY_PATH="$TEST42F_DIR/bin:$DYLD_FALLBACK_LIBRARY_PATH"
	make test
	export DYLD_FALLBACK_LIBRARY_PATH=`echo $DYLD_FALLBACK_LIBRARY_PATH | sed -e 's/^[^:]*://g'`
	cd ../..


if [ 0 -lt $# ] && [ "$1" = "--norm" ]
then

	print $Cyan "Checking norm...\n"
	IFS=$' ' GLOBIGNORE='*' command eval 'submits=($SUBMIT)'
	for submit in "${submits[@]}"
	do
		norminette -R CheckForbiddenSourceHeader $submit
	done
fi
print $Yellow "=====================================================\n"
exit 0
