#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, m;
    Int a[1001], b[1001], c[1001][20];
    cin >> n >> m;
    for(Int i=1; i<=m; i++){
        cin >> a[i] >> b[i];
        for(Int j=1; j<=b[i]; j++){
            cin >> c[i][j];
        }
    }

    const int INF = 1e9;
    vector<Int> dp(10001, INF);
    dp[0] = 0;

    for(Int i=1; i<=m; i++){
        Int now = 0;
        for(Int j=1; j<=b[i]; j++){
            now |= (1 << c[i][j] - 1);
        }
        for(Int bit=0; bit < (1<<n); bit++){
            if(dp[bit | now] > dp[bit]+a[i]){
                dp[bit | now] = dp[bit] + a[i];
            }
        }
    }

    if(dp[(1<<n)-1] == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << dp[(1<<n)-1] << endl;

    return 0;
}