#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    double n, k;
    cin >> n >> k;

    double rate = 0.0;
    if(k <= n){
        rate += (n-k+1)/n;
    }

    Int mx = k<=n ? k-1 : n;
    for(Int i=1; i<=mx; i++){
        tmpd = i;
        double cnt = 0.0;
        while(tmpd < k){
            tmpd *= 2.0;
            cnt++;
        }
        rate += pow(0.5, cnt)*(1.0/n);
    }
    printf("%.10lf", rate);
    return 0;
}