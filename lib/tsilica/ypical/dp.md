# Dynamic Planning


## Knapsack

[例題](https://atcoder.jp/contests/dp/tasks/dp_d) | [参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%8C%BA%E9%96%93-dp)

n 個の品物があり、i 番目の品物のそれぞれ重さと価値が w[i]、v[i] となっている (i = 0, 1, ..., n−1)。
これらの品物から重さの総和が W を超えないように選んだときの、価値の総和の最大値を求めよ。

##### 方針

<pre style="background-color:whitesmoke">
  dp[i][j]  >>>   i 番目までの品物の中で重さの総和が j 以下となるように選んだときの最大価値
</pre>

##### 漸化式

<pre style="background-color:whitesmoke">
  <strong>if</strong> j >= w[i] <strong>then</strong>
    dp[i+1][j] = max{ dp[i][j - w[i]] + v[i], dp[i][j] }
  <strong>else</strong>
    dp[i+1][j] = dp[i][j]
</pre>

##### 初期条件

<pre style="background-color:whitesmoke">
  <strong>for</strong> w <strong>in</strong> W
    dp[0][w] = 0
</pre>


## Number Partitioning 1

[例題](https://atcoder.jp/contests/arc029/tasks/arc029_1) | [参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-3%E9%83%A8%E5%88%86%E5%92%8C%E5%95%8F%E9%A1%8C)

n 個の正の整数 a[0], a[1], …, a[n−1] と正の整数 A が与えられる。
これらの整数から何個かの整数を選んで総和が A になるようにすることが可能か判定せよ。

##### 方針

<pre style="background-color:whitesmoke">
  dp[i][j]  >>>   i番目までの整数の中からいくつか選んで総和をjとすることが可能かどうか
</pre>

##### 漸化式

<pre style="background-color:whitesmoke">
  <strong>if</strong> j >= a[i] <strong>then</strong>
    dp[i+1][j] = dp[i][j-a[i]] | dp[i][j]
  <strong>else</strong>
    dp[i+1][j] = dp[i][j]
</pre>

##### 初期条件

<pre style="background-color:whitesmoke">
  <strong>for</strong> j <strong>in</strong> A
    <strong>if</strong> j = 0 <strong>then</strong>
      dp[0][j] = True
    <strong>else</strong>
      dp[0][j] = False
</pre>
