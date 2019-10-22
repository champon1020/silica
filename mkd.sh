#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Error: $# arguments is over required"
    echo "Only 'two' arguments is needed"
    exit 1
fi

BASE_DIR=$1
BASE_NUM=$2

if [ $BASE_DIR != "beginer" ] && [ $BASE_DIR != "regular" ] && [ $BASE_DIR != "grand" ]; then
    echo "Error: '$BASE_DIR' is unsuitable directory name"
    echo "Select one in 'beginer', 'regular' or 'grand'"
    exit 1
fi

if ! expr $BASE_NUM : "[0-9]\{3\}$" > /dev/null; then
    echo "Error: '$BASE_NUM' is unsuitable base file name"
    echo "You can use only three numbers, for example '123'"
    exit 1
fi

SCRIPT_DIR=$(cd $(dirname $0); pwd)

cd $SCRIPT_DIR/$BASE_DIR

case $BASE_DIR in
    "beginer" ) 
        if [ -e "abc$BASE_NUM" ]; then
            echo "Error: 'abc$BASE_NUM' directory is already exist"
            exit 1
        else
            mkdir "abc$BASE_NUM"
            echo "Create '$BASE_DIR/abc$BASE_NUM'"
            cd abc$BASE_NUM
            BASE_FILE=abc$BASE_NUM
        fi;;

    "regular" ) 
        if [ -e "arc$BASE_NUM" ]; then
            echo "Error: 'arc$BASE_NUM' directory is already exist"
            exit 1
        else
            mkdir "arc$BASE_NUM"
            echo "Create '$BASE_DIR/arc$BASE_NUM'"
            cd arc$BASE_NUM
            BASE_FILE=arc$BASE_NUM
        fi;;

    "grand" ) 
        if [ -e "agc$BASE_NUM" ]; then
            echo "Error: 'agc$BASE_NUM' directory is already exist"
            exit 1
        else
            mkdir "agc$BASE_NUM"
            echo "Create '$BASE_DIR/agc$BASE_NUM'"
            cd agc$BASE_NUM
            BASE_FILE=agc$BASE_NUM
        fi;;
esac


if [ ${BASE_DIR} = "regular" ]; then
    touch ${BASE_FILE}c.cpp
    touch ${BASE_FILE}d.cpp
    touch ${BASE_FILE}e.cpp
    touch ${BASE_FILE}f.cpp

    echo "Create '${BASE_FILE}c.cpp'"
    echo "Create '${BASE_FILE}d.cpp'"
    echo "Create '${BASE_FILE}e.cpp'"
    echo "Create '${BASE_FILE}f.cpp'"
else
    touch ${BASE_FILE}a.cpp
    touch ${BASE_FILE}b.cpp
    touch ${BASE_FILE}c.cpp
    touch ${BASE_FILE}d.cpp

    echo "Create '${BASE_FILE}a.cpp'"
    echo "Create '${BASE_FILE}b.cpp'"
    echo "Create '${BASE_FILE}c.cpp'"
    echo "Create '${BASE_FILE}d.cpp'"
fi
