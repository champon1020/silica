#!/bin/bash

usage () {
	echo "usage"
}

declare LOWER
tolower () {
    LOWER=$(echo "$1" | tr '[:upper:]' '[:lower:]')
}

declare UPPER
toupper() {
    UPPER=$(echo "$1" | tr '[:lower:]' '[:upper:]')
}

# (TASK_LIMIT, URL, ISUPPER)
build () {
	for t in {a..z}; do
		tolower $t
		toupper $t
		
		if [ $3 = true ]; then
			ALPHABET=$UPPER
		else
			ALPHABET=$LOWER
		fi

		mkdir "tasks/task${UPPER}"
		
		cd "${PWD}/tasks/task${UPPER}"
		oj d "${2}${ALPHABET}"
		cd "../../"
		
		echo "Make dir task ${UPPER}"

		if [ $t = $1 ]; then
			break
		fi
	done
}

# (OPTIONS)
parse_options () {
	for OPT in $@; do
		case $OPT in
			-h | --help)
				usage
				exit 1
				;;
			-p | --provider)
				PROVIDER=$2
				shift 2
				;;
			-t | --task)
				tolower $2
				TASK_LIMIT=$LOWER
				shift 2
				;;
		esac
	done
}

if [ $# = 0 ] || [[ $1 = *"-"* ]]; then
	echo "ERROR"
	usage
	exit 1
fi

CONTEST=$1
shift 1

PROVIDER="atcoder"
TASK_LIMIT="f"
PWD=$(cd $(dirname $0); pwd)

parse_options $@

# backup tasks
if [ -e tasks/.backup ]; then
	rm -rf tasks/.backup/**
else
	mkdir tasks/.backup
fi
mv tasks/task* tasks/.backup/
		
# clean tasks directory
rm -rf tasks/task*

case $PROVIDER in
	"atcoder")
		echo "Contest Provider: AtCoder"
		URL="https://atcoder.jp/contests/${CONTEST}/tasks/${CONTEST}_"
	    build $TASK_LIMIT $URL false
		;;
	"cf" | "codeforces")
		echo "Contest Provider: Codeforces"
		URL="https://codeforces.com/contest/${CONTEST}/problem/"
		build $TASK_LIMIT $URL true
		;;
esac

echo "Success!!"

