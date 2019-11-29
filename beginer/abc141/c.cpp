#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long n, k, q;
    long a[100000];
    long tmp;
    cin >> n >> k >> q;
    for(long i=0; i<n; i++){
        a[i] = 0;
    }
    for(long i=0; i<q; i++){
        cin >> tmp;
        a[tmp-1]++;
    }
    for(long i=0; i<n; i++){
        if(k - (q-a[i]) <= 0){
            cout << "No" << endl;
        }else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}