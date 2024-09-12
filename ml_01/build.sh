#!/bin/bash

set -xe

clang -Wall -Wextra twice.c -o twice -lm
clang -Wall -Wextra gates.c -o gates -lm
clang -Wall -Wextra xor.c -o xor -lm
