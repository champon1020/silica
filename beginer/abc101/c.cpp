#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, k;
    Int a[100001];
    Int marker;
    cin >> n >> k;
    for(Int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]==1) marker=i;
    }

    // Int i = 0;
    // Int cnt = 0;
    // if(marker==0){
    //     cnt += (n-1 + k-2)/(k-1);
    // }else{
    //     while(i<n){
    //         if(i<=marker && marker<=i+k-1){
    //             cnt++;
    //             i=marker+1;
    //             continue;
    //         }
    //         i += k-1;
    //         cnt++;
    //     }
    // }

    cout << (n-1 + k-2)/(k-1) << endl;

    return 0;
}