#!/bin/sh

if [ ! -f .42framework ]
then
	echo "You can only execute this script in a repo initialized with the 'init42' command."
	exit
fi

NB_FILES= `find * -name "ex*" | wc -l | bc | tr -d '\n'`

for i in {0..$NB_FILES}
do
	sh test.sh i
done
exit
