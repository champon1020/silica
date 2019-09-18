#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int a, b;
    cin >> a >> b;
    if((a+b)%2 != 0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << (a+b)/2 << endl;
    }

    return 0;
}