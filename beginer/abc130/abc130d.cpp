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
    Int a[100000];
    cin >> n >> k;
    for(Int i=0; i<n; i++){
        cin >> a[i];
    }

    Int ans = 0;
    Int r=0;
    Int sum = 0;
    for(Int i=0; i<n; i++){
        while(sum<k){
            if(r==n){
                break;
            }else{
                sum += a[r];
                r++;
            }
        }
        if(sum < k){
            break;
        }
        ans += n-r+1;
        sum -= a[i];
    }
    cout << ans << endl;

    return 0;
}