#!/bin/bash

usage () {
	echo "Usage: bash copy.sh [task alphabet]"
}

declare UPPER
toupper() {
    UPPER=$(echo "$1" | tr '[:lower:]' '[:upper:]')
}

if [ $# = 0 ] || [ $1 = "-h" ]; then
	usage
	exit 1
fi

if [ $# != 1 ]; then
	echo "ERROR: the number of arguments must be 1, but got $#"
	exit 1
fi

toupper $1
cat task${UPPER}/main.cpp | xsel --clipboard --input

echo "copied task ${UPPER} to clipboard"
