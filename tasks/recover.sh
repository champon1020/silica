#!/bin/bash

usage () {
	echo "Usage: bash recover.sh [task alphabet]"
}

declare UPPER
toupper() {
    UPPER=$(echo "$1" | tr '[:lower:]' '[:upper:]')
}

if [ $# = 0 ] || [ $1 = "-h" ]; then
	usage
	exit 1
fi

if [ $# = 1 ]; then
	toupper $1
	mv .backup/task${UPPER} ./
	echo "recovered task${UPPER}"
else
	echo "ERROR: the number of arguments must be $1, but got $#"
	usage
	exit 1
fi
	
