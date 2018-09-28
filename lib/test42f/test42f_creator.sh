#!/bin/sh

cd bin
gcc -Wall -Wextra -Werror -fpic -c ../include/test42f.h ../src/test42f_*.c
gcc -shared -o libtest42f.so test42f_*.o
cd ..
