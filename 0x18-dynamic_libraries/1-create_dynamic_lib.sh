#!/bin/bash
gcc -c -Wall _Werror -fpic *.c
gcc -shared -o liball.so *.o
