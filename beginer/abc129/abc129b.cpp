#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmp = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int w[100000];
    Int ws[10000];
    Int n;
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> w[i];
        if(i==0){
            ws[i] = w[i];
            continue;
        }
        ws[i] = ws[i-1] + w[i];
    }

    Int min = 10000000;
    Int sum = ws[n-1];
    for(Int i=0; i<n; i++){
        min = abs(sum-2*ws[i]) < min ? abs(sum-2*ws[i]) : min;
    }
    cout << min << endl;
    return 0;
}