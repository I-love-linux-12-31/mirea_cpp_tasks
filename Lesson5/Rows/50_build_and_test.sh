#!/bin/bash

(g++ 50.cpp -o out.o -O3) && echo -e "3 5 9\n12 9 8\n6 5 4\n0 6 2\n3 1 2\n10 10 5\n9 6 3\n6 3 4\n2 4 6\n5 1 4" | ./out.o
