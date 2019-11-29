#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, d;
    cin >> n >> d;
    int ans = 0;
    while(n > 0){
        n -= d*2+1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}