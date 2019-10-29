# Dynamic Planning


## Knapsack
[問題](https://atcoder.jp/contests/dp/tasks/dp_d) | 
[参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%8C%BA%E9%96%93-dp)

n 個の品物があり、i 番目の品物のそれぞれ重さと価値が w[ i ]、v[ i ] となっている (i=0,1,...,n−1)。
これらの品物から重さの総和が W を超えないように選んだときの、価値の総和の最大値を求めよ。

<dl>
  <dt>
    <strong>方針</strong>
  </dt>
  <dd>
    <span style="color:plum;">dp[ i ][ j ]</span>　==>　i 番目までの品物の中から重さが j を超えないように選んだ時の最大価値
  </dd>
  <dd>
    <span style="color:plum;">ans</span>　==>　dp[ n ][ W ]
  </dd>

  <dt>
    <strong>漸化式</strong>
  </dt>
  <dd>
    <span style="color:khaki;">j >= w[ i ]</span>　==>　dp[ i+1 ][ j ] = max( dp[ i ][ j - w[ i ] ] + v[ i ], dp[ i ][ j ] )
  </dd>
  <dd>
    <span style="color:khaki;">other</span>　==>　dp[ i+1 ][ j ] = dp[ i ][ j ]
  </dd>
<dl>

---

## Number Partitioning 1
