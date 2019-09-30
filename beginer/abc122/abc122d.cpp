#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n;
    cin >> n;

    Int inf = 1e9;
    Int dp[500][20];

    Int len = n%2==0 ? n/2 : (n+1)/2;

    if(n%2==1){
        dp[1][1] = 1;
        dp[1][6] = 1;
        dp[1][9] = 1;
    }
    for(Int i=2; i<=n/2; i++){
        for(Int j=0; j<16; j++){
            if(j==1){
                for(Int k=8; k<12; k++){
                    dp[i][k] += dp[i-1][j] + 1;
                }
                for(Int k=0; k<16; k++){
                    if(k%4 != 2) continue;
                    dp[i][j] += dp[i-1][k] + 1;
                }
            }
            else if(j==2 || j==8){
                for(Int k=4; k<8; k++){
                    dp[i][k] += dp[i-1][j] + 1;
                }
            }
            else if(j==6 || j==9){
                for(Int k=0; k<16; k++){
                    if(k%4 != 0) continue;
                    dp[i][j] += dp[i-1][k] + 1;
                }
            }
            else {
                for(Int k=0; k<16; k++){
                    dp[i][j] += dp[i-1][k];
                }
            }


            // if(j==1){
            //     for(Int k=8; k<12; k++){
            //         dp[i][k]++;
            //     }
            //     for(Int k=0; k<16; k++){
            //         if(k%4 != 2) continue;
            //         dp[i][j]++;
            //     }
            // }
            // else if(j==2 || j==8){
            //     for(Int k=4; k<8; k++){
            //         dp[i][k]++;
            //     }
            // }
            // else if(j==6 || j==9){
            //     for(Int k=0; k<16; k++){
            //         if(k%4 != 0) continue;
            //         dp[i][j]++;
            //     }
            // }

            // for(Int k=0; k<16; k++){
            //     dp[i][j] += dp[i-1][k];
            // }
            
            dp[i][j] %= inf;
        }
    }
    
    Int sum = 0;
    for(Int j=0; j<16; j++){
        sum += dp[n/2][j];
        cout << dp[n/2][j] << " ";
    }
    cout << endl;

    Int num = pow(4,n);
    cout << (num-sum)%inf << endl;

    return 0;
}