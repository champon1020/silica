#!/bin/bash

for filename in ./grand/**/*.cpp; do
  FILENAME="${filename##*/}"
  DIR="${filename%/*}/"
  NEW_BASE_FILENAME="${FILENAME%.*}"
  NEW_FILENAME=${NEW_BASE_FILENAME:6:7}

  if [ ${#FILENAME} -lt 11 ]; then
    #echo "$FILENAME ${#FILENAME}"
    continue;
  fi

  mv "$filename" "${DIR}${NEW_FILENAME}.cpp"
  echo "$filename => ${DIR}${NEW_FILENAME}.cpp"
done;