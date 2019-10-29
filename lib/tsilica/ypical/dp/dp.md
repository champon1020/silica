# Dynamic Planning


## Knapsack

[問題](https://atcoder.jp/contests/dp/tasks/dp_d) | [参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%8C%BA%E9%96%93-dp)

n 個の品物があり、i 番目の品物のそれぞれ重さと価値が w[ i ]、v[ i ] となっている (i=0,1,...,n−1)。
これらの品物から重さの総和が W を超えないように選んだときの、価値の総和の最大値を求めよ。

##### 方針
```math
  dp_{ij} : i 番目までの品物の中で重さの総和が j 以下となるように選んだときの最大価値
  \\
  answer : dp_{nw}
```


## Number Partitioning 1
