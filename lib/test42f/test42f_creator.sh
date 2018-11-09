#!/bin/sh

cd bin
gcc -Wall -Wextra -Werror -c ../include/test42f.h ../src/test42f_*.c
ar -rcs libtest42f.a test42f_*.o
cd ..
