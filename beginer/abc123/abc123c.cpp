#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, t[6];
    cin >> n;
    for(Int i=0; i<5; i++){
        cin >> t[i];
    }

    Int mint = pow(10, 15)+2;
    Int minind = 0;
    for(Int i=0; i<5; i++){
        if(t[i] < mint){
            mint = t[i];
            minind = i;
        }
    }
    
    Int ans = ceil(double(n)/double(mint)) + minind + 5-(minind+1);
    cout << ans << endl;
    return 0;
}