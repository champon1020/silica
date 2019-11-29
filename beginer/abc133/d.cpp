#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n;
    Int a[100000], b[100000];
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> a[i];
    }

    Int sum=0;
    for(Int i=0; i<n; i++){
        if((i+1)%2==0){
            sum-=a[i];
        }else{
            sum+=a[i];
        }
    }
    b[0] = sum;
    for(Int i=1; i<n; i++){
        b[i] = 2*a[i-1]-b[i-1];
    }
    for(Int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}