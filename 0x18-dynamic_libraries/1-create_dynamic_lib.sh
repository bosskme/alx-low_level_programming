#!/bin/bash

#compile all the .c files into object files
gcc -c -Wall _Werror -fpic *.c

#create the dynamic library
gcc -shared -o liball.so *.o
