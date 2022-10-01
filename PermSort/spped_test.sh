#!/bin/bash

time python3 PermSort.py
g++ PermSort.cpp -o PermSort.o
time ./PermSort.o
