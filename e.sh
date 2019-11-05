#!/bin/bash

if [ $# -ne 3 ]; then
	echo "Error: arguments should be 3"
	exit 1
fi


case $1 in
	"g"	)
		DIR=~/ipad/silica/grand/;;
	"r" )
		DIR=~/ipad/silica/regular/;;
	"b" )
		DIR=~/ipad/silica/beginer/;;	
esac


FILE=a${1}c${2}${3}.cpp
FILE_DIR=a${1}c${2}/

cd $DIR
FILE_PATH=${FILE_DIR}${FILE}
echo $FILE_PATH

if [ -e $FILE_PATH ]; then
	cd $FILE_DIR
	if [ ! -e bin/ ]; then
		mkdir "bin/"
		echo "Created ${FILE_DIR}bin"
	fi
	
	g++ $FILE -o bin/${FILE}
	./bin/$FILE
else
	echo "Error: '${DIR}${FILE_PATH}' is not exist"
fi
