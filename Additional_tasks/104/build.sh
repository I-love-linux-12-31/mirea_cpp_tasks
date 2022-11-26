#!/bin/bash

g++ 104.cpp -O3 -msse2 -msse3 -lsqlite3 '/usr/local/lib64/libyaml-cpp.so.0.7' -m64 -o 104.o