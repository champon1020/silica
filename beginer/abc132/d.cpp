#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


Int inf = pow(10, 9)+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, k;
    Int c[2001][2001];
    cin >> n >> k;

    c[0][0] = 1;
    for(Int i=1; i<=2000; i++){
        c[i][0] = 1;
        for(Int j=1; j<=2000; j++){
            if(i == j){
                c[i][j] = 1;
                continue;
            }
            if(i < j){
                c[i][j] = 0;
                continue;
            }
            c[i][j] = c[i-1][j]%inf + c[i-1][j-1]%inf;
        }
    }
    for(Int i=1; i<=k; i++){
        Int c1 = c[n-k+1][i] * c[k-1][i-1];
        cout << c1%inf << " ";
    }
    cout << endl;

    return 0;
}