# Dynamic Planning

## Knapsack
[問題](https://atcoder.jp/contests/dp/tasks/dp_d) | 
[参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%8C%BA%E9%96%93-dp)

n 個の品物があり、i 番目の品物のそれぞれ重さと価値が w[ i ]、v[ i ] となっている (i=0,1,...,n−1)。
これらの品物から重さの総和が W を超えないように選んだときの、価値の総和の最大値を求めよ。

#### 方針
dp[ i ][ j ]　==>　i 番目までの品物の中から重さが j を超えないように選んだ時の最大価値

ans　==>　dp[n][W]

#### 漸化式

dp[ i+1 ][ j ] = max( dp[ i ][ j -w[ i ] ] + v[ i ], dp[ i ][ j ] )　( j >= w[ i ] )

dp[ i+1 ][ j ] = dp[ i ][ j ] ( other )


## Number Partitioning 1
