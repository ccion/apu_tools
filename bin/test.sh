#!/bin/bash

export LD_LIBRARY_PATH=/snap/core/6350/lib/x86_64-linux-gnu/
./clang -Os -c arithmetic_acf.cpp -o test
