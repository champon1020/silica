#!/bin/bash

# arguments: (url, problem) or (provider, contest, problem)
if [ $# != 2 ] && [ $# != 3 ]; then
	echo "ERROR: the number of arguments must be 2 or 3, but got $#"
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


if [ $# = 2 ]; then
	echo "DOWNLOAD $1 as $2"
	toupper $2
	oj d $1 -d test${UPPER}
	exit 1
fi

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
