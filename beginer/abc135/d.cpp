#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char s[100001];
    cin >> s;

    Int dp[100001][13];
    Int len = strlen(s);
    Int inf = 1e9+7;

    dp[0][0] = 1;
    for(Int i=0; i<len; i++){
        if(s[i] != '?'){
            Int num = s[i]-'0';
            for(Int k=0; k<13; k++){
                dp[i+1][(k*10 + num)%13] += dp[i][k];
            }
        }else{
            for(Int j=0; j<10; j++){
                for(Int k=0; k<13; k++){
                    dp[i+1][(k*10 + j)%13] += dp[i][k];
                }
            }
        }
        for(Int j=0; j<13; j++){
            dp[i+1][j] %= inf;
        }
    }

    cout << dp[len][5] << endl;

    return 0;
}