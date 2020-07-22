#!/bin/bash

if [ $# != 1 ]; then
	echo "the number of arguments must be 1, but got $#"
	exit 1
fi

if [ -e $1.cpp ]; then
	mv $1.cpp .backup/
fi

cp ../template.cpp $1.cpp

echo "made $1.cpp"
