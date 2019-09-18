#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, p, cnt=0, tmp = 0;
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> p;
        if(p != i+1){
            cnt++;
        }
    }
    if(cnt <= 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}