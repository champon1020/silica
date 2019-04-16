#! /bin/sh

var=$1
name=$(basename "$var")
fname=${name%.*}

g++ $1 -o D:/Alfheim/bin/win/$fname
D:/Alfheim/bin/win/$fname.exe
