#!/bin/bash

#$1 is argument that takes directory
#type d find directories
#type f find files
find $1 -type d | wc -l |xargs

find $1 -type f | wc -l |xargs
