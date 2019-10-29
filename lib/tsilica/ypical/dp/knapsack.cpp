#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<=e; i++)
using namespace std;
using ll = long long;


// dp[i][j] => i 番目までの品物の中から j を超えないように選んだ時の最大価値
ll n, W;
ll dp[110][100010];
ll w[110], v[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> W;
    rep(i, n){
        cin >> w[i] >> v[i];
    }

    // 初期化
    reps(j, 0, W){
        dp[0][j] = 0;
    }

    // 漸化式
    rep(i, n){
        reps(j, 0, W){
            if(j >= w[i]){
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}
