#!/bin/bash

usage () {
	echo "Usage: bash make.sh [task alphabet]"
}

declare UPPER
toupper() {
    UPPER=$(echo "$1" | tr '[:lower:]' '[:upper:]')
}

if [ $# = 0 ] || [ $1 = "-h" ]; then
	usage
	exit 1
fi

if [ $# -ne 1 ]; then
	echo "the number of arguments must be 1, but got $#"
	exit 1
fi

toupper $1
if [ -e task${UPPER} ]; then
	rm -rf .backup/task${UPPER}
	mv task${UPPER} .backup/
fi

mkdir task${UPPER}
cp ../template.cpp task${UPPER}/main.cpp

echo "made task${UPPER}"
