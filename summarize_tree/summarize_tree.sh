#!/bin/bash

#$1 is agrument of directory

num_dirs=$(find $1 -type d | wc -l)

num_regular=$(find $1 -type f | wc -l)

echo $num_dirs
echo $num_files

