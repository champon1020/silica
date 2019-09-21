#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, x;
    Int l[1000];
    cin >> n >> x;
    for(Int i=0; i<n; i++){
        cin >> l[i];
    }

    Int cnt = 0;
    Int d = 0;
    for(Int i=0; i<n; i++){
        if(d>x){
            break;
        }
        cnt++;
        d += l[i];
    }
    if(d<=x){
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}