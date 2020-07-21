#!/bin/bash

usage () {
	echo "Usage: bash clean.sh <task alphabet>"
}

declare UPPER
toupper() {
    UPPER=$(echo "$1" | tr '[:lower:]' '[:upper:]')
}

if [ $# = 0 ] || [ $1 = "-h" ]; then
	usage
	exit 1
fi

if [ -ne ".backup" ]; then
	mkdir ".backup"
fi

if [ $# = 0 ]; then
	mv ./** .backup/
	rm -rf ./task*
	echo "remove all tasks"
else
	toupper $1
	mv ./task${UPPER} .backup/
	rm -rf ./task${UPPER}
	echo "remove task${UPPER}"
fi
