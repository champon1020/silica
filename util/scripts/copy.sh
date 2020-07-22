#!/bin/bash

if [ $# != 1 ]; then
	echo "ERROR: the number of arguments must be 1, but got $#"
	exit 1
fi

if [ ! -e $1.cpp ]; then
	echo "ERROR: $1.cpp is not exist"
	exit 1
fi

cat $1.cpp | xsel --clipboard --input

echo "copied task ${UPPER} to clipboard"
