#!/bin/bash

usage () {
	echo "Usage: bash lib.sh [lib name]"
}

copy () {
	cat $1 | xsel --clipboard --input
}

if [ $# = 0 ] || [ $1 = "-h" ]; then
	usage
	exit 1
fi

if [ $# -ne 1 ]; then
	echo "ERROR: the nubmer of arguments must be 1, but got $#"
	exit 1
fi

case $1 in
	debug)
		copy ../debug/$1.hpp
		echo "copied ../debug/$1.hpp"
		;;
	bellmanford | dijkstra | kruskal | lca | topological | warshallfloyd)
		copy ../graph/$1.hpp
		echo "copied ../graph/$1.hpp"
		;;
	combination | finv | math | mint | permutation)
		copy ../math/$1.hpp
		echo "copied ../math/$1.hpp"
		;;
	z)
		copy ../string/$1.hpp
		echo "copied ../string/$1.hpp"
		;;
	fenwick | segtree | sparsetable | unionfind)
		copy ../structure/$1.hpp
		echo "copied ../structure/$1.hpp"
		;;
esac
	
