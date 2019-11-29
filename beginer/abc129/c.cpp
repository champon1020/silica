#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmp = 0;
double tmpd = 0.0;


Int inf = pow(10,9)+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, m;
    cin >> n >> m;
    Int a[100001];
    Int c[100001];
    a[0] = -1;
    for(Int i=1; i<=m; i++){
        cin >> a[i];
        if(a[i] == a[i-1]+1){
            cout << "0" << endl;
            return 0;
        }
    }

    c[0] = 1;
    c[1] = 1;
    c[2] = 2;
    for(Int i=3; i<=n; i++){
        c[i] = (c[i-1] + c[i-2])%inf;
    }

    Int cnt = 1;
    for(Int i=0; i<m; i++){
        Int diff = (a[i+1]-1) - (a[i]+1);
        cnt *= c[diff];
        cnt %= inf;
    }
    Int diff = n - (a[m]+1);
    cnt *= c[diff];
    cnt %= inf;
    cout << cnt << endl;

    return 0;
}