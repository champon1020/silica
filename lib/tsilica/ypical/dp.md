# Dynamic Programming


## Knapsack

[例題](https://atcoder.jp/contests/dp/tasks/dp_d) | [参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%8C%BA%E9%96%93-dp)

n 個の品物があり，i 番目の品物のそれぞれ重さと価値が w[i]、v[i] となっている.
これらの品物から重さの総和が W を超えないように選んだときの、価値の総和の最大値を求める．

##### 方針

<pre style="background-color:gainsboro">
  dp[i+1][j]  >>>   i 番目までの品物の中で重さの総和が j 以下となるように選んだときの最大価値
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  <strong>if</strong> j >= w[i] <strong>then</strong>
    dp[i+1][j] = max{ dp[i][j - w[i]] + v[i], dp[i][j] }
  <strong>else</strong>
    dp[i+1][j] = dp[i][j]
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  <strong>REP</strong>(j, 0, W)
    dp[0][j] = 0
</pre>
<br>



## Number Partitioning 1

[例題](https://atcoder.jp/contests/arc029/tasks/arc029_1) | [参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-3%E9%83%A8%E5%88%86%E5%92%8C%E5%95%8F%E9%A1%8C)

n 個の正の整数 a[0], a[1], …, a[n−1] の部分和が整数 A になるものはあるか．

##### 方針

<pre style="background-color:gainsboro">
  dp[i+1][j]  >>>   i番目までの整数の中からいくつか選んで総和をjとすることが可能かどうか
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  <strong>if</strong> j >= a[i] <strong>then</strong>
    dp[i+1][j] = dp[i][j-a[i]] | dp[i][j]
  <strong>else</strong>
    dp[i+1][j] = dp[i][j]
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  <strong>REP</strong>(j, 0, A)
    dp[0][j] = (j==0) ? True : False
</pre>
<br>



## Number Partitioning 2　(部分和数え上げ)

[参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-4%E9%83%A8%E5%88%86%E5%92%8C%E6%95%B0%E3%81%88%E4%B8%8A%E3%81%92%E5%95%8F%E9%A1%8C)

n 個の正の整数 a[0], a[1], …, a[n−1] から何個か選んで，総和を整数 A にする方法は何通りあるか． (答えは mod 1e9+7)

ただし，indexが異なるものは異なる組み合わせとみなす．

##### 方針

<pre style="background-color:gainsboro">
  dp[i+1][j]  >>>   i番目までの整数からいくつか選んで総和をjとする場合の数
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  <strong>if</strong> j >= a[i] <strong>then</strong>
    dp[i+1][j] += dp[i][j - a[i]]

  dp[i+1][j] += dp[i][j]
  dp[i+1][j] %= MOD;
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  <strong>REP</strong>(j, 0, A)
    dp[0][j] = (j==0) ? 1 : 0;
</pre>
<br>



## Number Partitioning 3 （最小個数部分和）

[参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-5%E6%9C%80%E5%B0%8F%E5%80%8B%E6%95%B0%E9%83%A8%E5%88%86%E5%92%8C%E5%95%8F%E9%A1%8C)

n 個の整数 a[0], a[1], …, a[n−1] から何個か選んで総和を A にする方法を考えたとき，選ぶ整数の個数の最小値はどうなるか．（できない場合も有り）

##### 方針

<pre style="background-color:gainsboro">
  dp[i+1][j]  >>>   i番目までの整数からいくつか選んで総和をjとするときの選んだ整数の最小個数
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  <strong>if</strong> j >= a[i] <strong>then</strong>
    dp[i+1][j] = min{ dp[i][j - a[i]], dp[i][j] }
  <strong>else</strong>
    dp[i+1][j] = dp[i][j]
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  <strong>REP</strong>(j, 0, A)
    dp[0][j] = (j==0) ? 0 : infinity
</pre>
<br>



## Number Paritioning 4 （K個以内部分和）

[参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-6k%E5%80%8B%E4%BB%A5%E5%86%85%E9%83%A8%E5%88%86%E5%92%8C%E5%95%8F%E9%A1%8C)

n 個の整数 a[0], a[1], …, a[n−1] からK個以内の個数を選んで総和を A にすることは可能かどうか．

##### 方針

<pre style="background-color:gainsboro">
  dp[i+1][j][k] >>>   i番目までの整数からk個の整数を選んで総和をjにすることは可能かどうか
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  <strong>if</strong> j >= a[i] <strong>then</strong>
    <strong>if</strong> k + a[i] <= K <strong>then</strong>
      dp[i+1][j][k] = dp[i][j - a[i]][k-1] | dp[i][j][k]

  dp[i+1][j][k] |= dp[i][j][k]
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  <strong>REP</strong>(j, 0, A)
    dp[0][j][0] = (j==0) ? True : False
</pre>

しかし，これだと計算量が O(nKA) となるため微妙．
そこで，Nubmer Partitioning 1 の結果において

<pre style="background-color:gainsboro">
  (dp[n][A] <= K) ? YES : NO
</pre>

と表すことができる．これなら計算量は O(nA) で済む．

<br>



## LCS

[参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-8%E6%9C%80%E9%95%B7%E5%85%B1%E9%80%9A%E9%83%A8%E5%88%86%E5%88%97-lcs-%E5%95%8F%E9%A1%8C)

2つの文字 S, T の共通部分文字列の長さの最大値を求める．

※部分文字列とはその文字からいくつか抜き出して順に繋げてできる文字列のこと．

##### 方針

<pre style="background-color:gainsboro">
  dp[i+1][j+1]  >>>   Sのi文字目までとTのj文字目までの共通部分文字列の長さの最大値
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  <strong>if</strong> S[i] == T[j] <strong>then</strong>
    dp[i+1][j+1] = max{ dp[i+1][j], dp[i][j+1], dp[i][j] + 1 }
  <strong>else</strong>
    dp[i+1][j+1] = max{ dp[i+1][j], dp[i][j+1] }

  ※それぞれ dp[i+1][j+1] との比較も必要
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  dp[0][0] = 0
</pre>
<br>



## Minimum Cost Matching

[参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-9%E6%9C%80%E5%B0%8F%E3%82%B3%E3%82%B9%E3%83%88%E5%BC%BE%E6%80%A7%E3%83%9E%E3%83%83%E3%83%81%E3%83%B3%E3%82%B0%E5%95%8F%E9%A1%8C)

A = ( a[0], a[1], ... a[m-1] ) 及び B = ( b[0], b[1], ... b[n-1] ) において，ペア( a[i], b[j] ) をマッチさせたときのコスト c[i][j] の最小値を求める．

##### 方針

<pre style="background-color:gainsboro">
  dp[i+1][j+1]  >>>   a[i] までと b[j] までの最小コスト
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  dp[i+1][j+1] = min{ dp[i][j], dp[i+1][j], dp[i][j+1] } + c[i][j]

  ※それぞれ dp[i+1][j+1] との比較も必要
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  dp[0][0] = 0

  ※最小値を求めるので他は infinity にする
</pre>
<br>



## Lebenshtein

[例題](https://yukicoder.me/problems/no/225) | [参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-10%E3%83%AC%E3%83%BC%E3%83%99%E3%83%B3%E3%82%B7%E3%83%A5%E3%82%BF%E3%82%A4%E3%83%B3%E8%B7%9D%E9%9B%A2-diff%E3%82%B3%E3%83%9E%E3%83%B3%E3%83%89)

2つの文字列 S, T において，S に以下のうちいずれかの操作を加えて T に変換することを考える．

このときの最小操作回数はいくらか．

- S の中から1文字を選んで好きな文字に変更する
- S の中から1文字を選んで消去する
- S の好きな場所に文字を挿入する


##### 方針

<pre style="background-color:gainsboro">
  dp[i][j]  >>>   S の i 文字目までで T の j 文字目までに変換できるときの最小操作回数
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  <strong>if</strong> S[i] == T[j] <strong>then</strong>
    dp[i+1][j+1] = dp[i][j]
  <strong>else</strong>
    dp[i+1][j+1] = min{ dp[i][j], dp[i+1][j], dp[i][j+1] } + 1

  ※それぞれ dp[i+1][j+1] との比較も必要
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  dp[0][0] = 0;

  ※最小値を求めるので他は infinity にする
</pre>
<br>



## Section Partitioning （分かち書き，発電計画問題）

[参考](https://qiita.com/drken/items/a5e6fe22863b7992efdb#5-%E5%8C%BA%E9%96%93%E3%82%92%E5%88%86%E5%89%B2%E3%81%99%E3%82%8B%E5%95%8F%E9%A1%8C-----%E5%88%86%E3%81%8B%E3%81%A1%E6%9B%B8%E3%81%8D%E3%81%AA%E3%81%A9)

ナップザック問題などは，n 個の対象に対して「選ぶ」，「選ばない」を決めていたが，これは「n 個の対象を各区間に分割する最適化問題」である．

つまり，ここでは「仕切りを入れる」，「仕切りを入れない」を決める．


### 例1 発電計画問題

t = 0, 1, ..., T-1 のそれぞれの時刻について [t, t+1] の間に発電スイッチを ON または OFF にするかを決める．

発電計画において ON となっている区間が [ l[i], r[i] ] であった場合の利得は g[i][j] である．

このとき利得の最大値を求める．

##### 方針

<pre style="background-color:gainsboro">
  dp[t+1]   >>>   [t, t+1] で電源を入れたときの最大利得
</pre>

##### 漸化式

<pre style="background-color:gainsboro">
  dp[t+1] = max(dp[i] + g[i][j])    (0 <= i < j <= t)
</pre>

##### 初期条件

<pre style="background-color:gainsboro">
  dp[0] = 0
</pre>


### 例2 分かち書き

「これは僕のものです」 => 「これ　は　僕　の　もの　です」　のように単語ごとに区切る作業のこと．

##### 方針

<pre style="background-color:gainsboro">

</pre>

##### 漸化式

<pre style="background-color:gainsboro">

</pre>

##### 初期条件

<pre style="background-color:gainsboro">

</pre>
<br>
