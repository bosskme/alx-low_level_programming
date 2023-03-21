#!/bin/bash
gcc -c -Wall _Werror -fpic *.c
gcc -shared -o liball.so *.o
export LD_Library_PATH=.:$LD_LIBRARY_PATH
