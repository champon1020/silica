#!/bin/bash

if [ ! -e ".backup" ]; then
	mkdir ".backup"
fi

if [ $# = 0 ]; then
	for path in ./*.cpp; do
		if [ -f $path ]; then
			mv $path .backup/
		fi
	done

	for path in ./test*; do
		if [ -d $path ]; then
			cp -rf $path .backup/
			rm -rf $path
		fi
	done
	echo "backup and remove all tasks and tests"
else
	if [ ! -f ./$1.cpp ]; then
		if [ -d ./$1 ]; then
			cp -rf ./$1 .backup/
			echo "backup $1"
			
			rm -rf ./$1
			echo "remove $1"
		else
			echo "ERROR: $1.cpp is not exist"
			exit 1
		fi
	else
		mv ./$1.cpp .backup/
		echo "backup and remove $1.cpp"
	fi
fi
