#!/bin/bash

if [ $# != 1 ]; then
	echo "ERROR: the number of arguments must be $1, but got $#"
fi

if [ -e .backup/$1.cpp ]; then
	mv .backup/$1.cpp ./
	echo "recovered $1.cpp"
else
	echo "ERROR: .backup/$1.cpp is not exist"
	exit 1
fi
	
