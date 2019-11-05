#!/bin/bash

DIR=$1
FILE=$2

if [ $# -ne 3 ]; then
	echo "Error: arguments should be 3"
	exit 1
fi

if [ $1 != "b" ] && [ $1 != "r" ] && [ $1 != "g" ] && [ $1 != "o" ]; then
    echo "Error: '$1' is unsuitable directory name"
    echo "Select one in 'b', 'r' or 'g'"
    exit 1
fi

case $1 in
	"g"	)
		DIR=~/ipad/silica/grand/;;
	"r" )
		DIR=~/ipad/silica/regular/;;
	"b" )
		DIR=~/ipad/silica/beginer/;;
  "o" )
    DIR=~/ipad/silica/other/;;
esac


if [ $1 = "b" ] || [ $1 = "r" ] || [ $1 = "g" ]; then
  if ! expr $2 : "[0-9]\{3\}$" > /dev/null; then
      echo "Error: '$2' is unsuitable base file name"
      echo "You can use only three numbers, for example '123'"
      exit 1
  fi

  FILE=a${1}c${2}${3}.cpp
  FILE_DIR=a${1}c${2}/
else
  FILE_DIR=${2}/
  FILE=${3}.cpp
fi


cd $DIR

if [ -e ${FILE_DIR}${FILE} ]; then
	cd $FILE_DIR
	if [ ! -e bin/ ]; then
		mkdir "bin/"
		echo "Created ${FILE_DIR}bin"
	fi
	
  echo "Execute C++14"
	g++ $FILE -o bin/${FILE} -std=c++1y
	./bin/$FILE
else
	echo "Error: '${DIR}${FILE_DIR}${FILE}' is not exist"
fi
