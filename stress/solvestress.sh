#!/bin/bash

#echo solutions/codeforces/contest_2109/"$1"

g++ -fsanitize=undefined -fno-omit-frame-pointer -g \
-o ../../"$1".out -Wall -Wshadow -std=c++17 -Wno-unused-result \
-Wno-sign-compare -Wno-char-subscripts -Wconversion \
"$1".cpp -o "$1".out
