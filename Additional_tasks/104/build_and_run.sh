#!/bin/bash
clear
echo -e "\033[34mBuilding...\033[0m"
./build.sh
echo -e "\033[34mExecuting...\033[0m"
LD_LIBRARY_PATH="/usr/local/lib64/:$(pwd):$LD_LIBRARY_PATH" ./104.o