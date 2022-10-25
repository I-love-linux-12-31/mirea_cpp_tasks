#!/bin/bash

g++ 17.cpp -O3 -mcx16 -msse  -msse2 -msse3 -o 17_fast.o
time ./17_fast.o
