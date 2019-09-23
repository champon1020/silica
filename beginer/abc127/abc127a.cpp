#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmp = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int a, b;
    cin >> a >> b;

    if(a >= 13){
        cout << b << endl;
    }else if(a <= 5){
        cout << 0 << endl;
    }else{
        cout << b/2 << endl;
    }

    return 0;
}