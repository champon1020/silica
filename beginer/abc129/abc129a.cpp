#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmp = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int p, q, r;
    cin >> p >> q >> r;
    Int min = 1000000;
    min = p+q < p+r ? p+q : p+r;
    min = q+r < min ? q+r : min;
    cout << min << endl;

    return 0;
}