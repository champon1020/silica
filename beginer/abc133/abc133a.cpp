#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmp = 0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, a, b;
    cin >> n >> a >> b;

    if(a*n > b){
        cout << b << endl;
    }else{
        cout << a*n << endl;
    }

    return 0;
}