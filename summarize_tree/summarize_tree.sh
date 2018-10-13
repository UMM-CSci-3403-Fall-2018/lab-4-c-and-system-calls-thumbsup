#!/bin/bash

#$1 is agrument of directory
directory=$1
num_dirs=$(find $directory -type d | wc -l)
num_regular=$(find $directory -type f | wc -l)

echo There were $num_dirs directories.
echo There were $num_regular regular files.

