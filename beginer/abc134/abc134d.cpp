#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n;
    Int a[200005], b[200005];
    cin >> n;
    for(Int i=1; i<=n; i++){
        cin >> a[i];
        b[i] = 0;
    }
    Int m = 0;
    for(Int i=n; i>=1; i--){
        Int tmp = 0;
        for(Int j=2; j<=n/i; j++){
            tmp += b[i*j];
        }
        tmp += a[i];
        if(tmp%2 != a[i]){
            b[i] = a[i]==0 ? 1 : 0;
        }else{
            b[i] = a[i];
        }
        m += b[i];
    }
    cout << m << endl;
    for(Int i=1; i<=n; i++){
        if(b[i] == 1){
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}