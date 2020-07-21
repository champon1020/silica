#!/bin/bash

declare UPPER
toupper() {
	UPPER=$(echo $1 | tr "[:lower:]" "[:upper:]")
}

toupper $1

if [ ! -e test${UPPER} ]; then
	echo "ERROR: test${UPPER} is not exist"
	exit 1
fi

echo "TEST TASK '${UPPER}' SAMPLE CASE"
oj t -d test${UPPER} -c "./output"
