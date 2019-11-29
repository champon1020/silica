#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error: $# arguments is over required"
    echo "Only 'two' arguments is needed"
    exit 1
fi

if ! expr $1 : "[0-9]\{3\}$" > /dev/null; then
    echo "Error: '$1' is unsuitable base file name"
    echo "You can use only three numbers, for example '123'"
    exit 1
fi

DIR=~/repos/VSCodeWorkspace/silica/codeforces
cd $DIR

if [ -e "cr${1}" ]; then
    echo "Error: 'cr${1}' directory is already exist"
    exit 1
else
    mkdir "cr${1}"
    echo "Create 'codeforces/cr$1'"
    cd cr$1
fi

touch taska.cpp
touch taskb.cpp
touch taskc.cpp
touch taskd.cpp
touch taske.cpp
touch taskf.cpp

echo "Create 'taska.cpp'"
echo "Create 'taskb.cpp'"
echo "Create 'taskc.cpp'"
echo "Create 'taskd.cpp'"
echo "Create 'taske.cpp'"
echo "Create 'taskf.cpp'"
