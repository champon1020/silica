#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmp = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int r, d, x[1000];

    cin >> r >> d >> x[0];
    for(Int i=1; i<=10; i++){
        x[i] = x[i-1]*r - d;
        cout << x[i] << endl;
    }
    return 0;
}