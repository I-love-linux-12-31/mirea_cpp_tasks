#!/bin/bash

time python3 PermSort.py
g++ PermSort.cpp -o PermSort.o
time ./PermSort.o
g++ PermSort.cpp -o PermSort2.o -O3 -march=native -fomit-frame-pointer
time ./PermSort2.o
