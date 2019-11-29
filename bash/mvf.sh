#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Error: the number of $# arguments is not equal to required"
  echo "Failed"
  exit 1
fi

case $1 in
  "abc" )
    TO_DIR="beginer/abc$2/";;
  "arc" )
    TO_DIR="regular/arc$2/";;
  "agc" )
    TO_DIR="grand/agc$2/";;
  "com" )
    TO_DIR="company/$2/";;
  "cr" )
    TO_DIR="codeforces/cr$2/";;
  "ecr" )
    TO_DIR="codeforces/ed$2/";;
  * )
    echo "Error: first argument is not comfortable"
    echo "Failed"
    exit 1;;
esac

BASE_DIR=$(pwd)
DIR=$BASE_DIR/$TO_DIR
echo "Info: Contest => ./$TO_DIR"
echo "Info: Directory => $DIR"

if [ -e "$DIR" ]; then
  echo "Message: The directory has already exist"
else
  mkdir "$DIR"
  echo "Message: Created directory"
fi

for filename in ./tasks/*.cpp; do
  FILENAME=${filename##*/}
  if [ "$FILENAME" == "test.cpp" ] || [ "$FILENAME" == "out.cpp" ]; then
    continue
  fi
  NEW_FILENAME=$(echo "${FILENAME:0:1}" | tr '[A-Z]' '[a-z]').cpp
  cp "$filename" "${DIR}${NEW_FILENAME}"
  echo "Message: Moved '$filename' to './${TO_DIR}${NEW_FILENAME}'"
done

echo "Successed!"
