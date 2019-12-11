# 重複組み合わせDP

[問題]
<pre style="background-color:gainsboro">
  n種類の品物があり，i番目の品物はa[i]個ある．
  これらの中からM個選ぶ組み合わせの総数はいくらか．
  （同じ種類同士は区別しない．また答えはmod(1e9+7)で答える．)
  参照: p.67
</pre>

##### 方針
<pre style="background-color:gainsboro">
  dp[i+1][j]  >>>   i番目までの品物でj個選ぶ組み合わせの総数
</pre>

##### 漸化式
i番目の品物をk個選ぶとすると以下のようになる．
<pre style="background-color:gainsboro">
  dp[i+1][j] = dp[i][j-k]   (0 <= k <= min{j, a[i]})
</pre>
これだと計算量が O(nM^2) となってしまう．そこで，漸化式を変形する．

<br>

まず，j => j-1 にシフトする．
<pre style="background-color:gainsboro">
  dp[i+1][j] = dp[i][j-1-k]   (0 <= k <= min{j, a[i]})
</pre>
ここで，シフトした分で足りないもの，または余計に追加してしまったものを調整する．

0 <= k <= min{j, a[i]}なので
<pre style="background-color:gainsboro">
  足りないのは dp[i][j-k] の k=0 のとき
  余計なものは dp[i][j-1-k] の k=min{j, a[i]} のとき
</pre>
である．

つまり，以下の式が成り立つ．
<pre style="background-color:gainsboro">
  dp[i][j-k] = dp[i][j-1-k] + dp[i][j] - dp[j-1-min{j, a[i]}]   (0 <= k <= min{j, a[i]})
</pre>

ここで，min{j, a[i]}について考える．
<pre style="background-color:gainsboro">
  min{j, a[i]} = j のとき      >>>   dp[j-1-j] = dp[-1] = 0  （負のインデックスは0とする）
  min{j, a[i]} = a[i] のとき   >>>   dp[j-1-a[i]]  (j > a[i] なので j-1-a[i] > -1)
</pre>

よって以下のように変形できる．
<pre style="background-color:gainsboro">
  dp[i][j-k] = dp[i][j-1-k] + dp[i][j] - dp[j-1-a[i]]   (0 <= k <= min{j, a[i]})
</pre>

dp[i][j-1-k] に着目すると，
<pre style="background-color:gainsboro">
  k = min{j, a[i]} = j のとき    >>>   dp[j-1-k] = dp[-1] = 0
</pre>
となるので，kの区間を変更して
<pre style="background-color:gainsboro">
  dp[i][j-k] = dp[i][j-1-k] + dp[i][j] - dp[j-1-a[i]]   (0 <= k <= min{j-1, a[i]})
</pre>
と変形できる．

また，はじめに立てた式と比べると，
<pre style="background-color:gainsboro">
  はじめに立てた式    >>>   dp[i+1][j] = dp[i][j-k]   (0 <= k <= min{j, a[i]})
  先程の式の初項      >>>   dp[i][j-1-k]               (0 <= k <= min{j-1, a[i]})
</pre>
となるので
<pre style="background-color:gainsboro">
  dp[i][j-1-k] = dp[i+1][j-1]
</pre>
と表せる

<br>

以上の式変形より
<pre style="background-color:gainsboro">
  dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[j-1-a[i]]
</pre>
となる．

※実装時には，引き算が負の値にならないよう if 文で場合分けをする．
