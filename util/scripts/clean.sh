#!/bin/bash

if [ ! -e ".backup" ]; then
	mkdir ".backup"
fi

if [ $# = 0 ]; then
	mv ./*.cpp .backup/
	echo "remove all tasks"
else
	if [ ! -e ./$1.cpp ]; then
		echo "ERROR: $1.cpp is not exist"
		exit 1
	fi
	mv ./$1.cpp .backup/
	echo "remove $1.cpp"
fi
