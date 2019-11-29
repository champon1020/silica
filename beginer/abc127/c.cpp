#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmp = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, m, l, r;
    Int ll, rr;
    cin >> n >> m;

    Int cnt = 0;
    for(Int i=0; i<m; i++){
        cin >> ll >> rr;
        if(i==0){
            l = ll, r=rr;
            cnt = r-l+1;
            continue;
        }
        if(l <= ll && rr <= r){
            cnt = rr-ll+1;
            r = rr, l = ll;
            continue;
        }
        if(rr < l || r < ll){
            cnt = 0;
            break;
        }
        if(rr <= r){
            cnt = rr-l+1;
            r = rr;
        }
        if(l <= ll){
            cnt = r-ll+1;
            l = ll;
        }
    }   
    cout << cnt << endl;
    return 0;
}