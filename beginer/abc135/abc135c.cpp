#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n;
    cin >> n;
    Int a[100002];
    Int b[100002];
    for(Int i=0; i<=n; i++){
        cin >> a[i];
    }
    for(Int i=0; i<n; i++){
        cin >> b[i];
    }
    Int sum = 0;
    for(Int i=0; i<n; i++){
        Int kill = a[i] > b[i] ? b[i] : a[i];
        Int rest = b[i] - a[i];
        sum += kill;
        if(rest > 0){
            kill = a[i+1] > rest ? rest : a[i+1];
            a[i+1] -= kill;
            sum += kill;
        }
    }
    cout << sum << endl;

    return 0;
}