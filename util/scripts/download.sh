#!/bin/bash

# arguments: (url) or (provider, contest, problem)
if [ $# != 1 ] && [ $# != 3 ]; then
	echo "ERROR: the number of arguments must be 1 or 3, but got $#"
	exit 1
fi

if [ $# = 1 ]; then
	echo "DOWNLOAD $1"
	oj d $1
	exit 1
fi

declare UPPER
toupper () {
	UPPER=$(echo $1 | tr "[:lower:]" "[:upper:]")
}

declare LOWER
tolower () {
    LOWER=$(echo $1 | tr "[:upper:]" "[:lower:]")
}

PROVIDER=$1
CONTEST=$2
PROBLEM=$3

echo "DOWNLOAD: PROVIDER: ${PROVIDER}, CONTEST: ${CONTEST}, PROBLEM: ${PROBLEM}"
case $PROVIDER in
	"atc" | "atcoder")
		tolower $PROBLEM
		toupper $PROBLEM
		oj d "https://atcoder.jp/contests/${CONTEST}/tasks/${CONTEST}_${LOWER}" -d test${UPPER}
		;;
	"cf" | "codeforces")
		toupper $PROBLEM
		oj d "https://codeforces.com/contest/${CONTEST}/problem/${UPPER}" -d test${UPPER}
		;;
	"*")
		echo "ERROR: provider is not supported"
		exit 1
esac
