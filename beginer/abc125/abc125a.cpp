#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int a, b, t;
    cin >> a >> b >> t;
    
    Int cnt = 0;
    Int time = a;
    
    if(a>t){
        cout << 0 << endl;
        return 0;
    }
    while(time <= t){
        cnt += b;
        time += a;
    }
    cout << cnt << endl;

    return 0;
}