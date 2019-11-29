#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int l, r;
    cin >> l >> r;

    Int min = pow(10, 18);
    for(Int i=l; i<r; i++){
        for(Int j=i+1; j<=r; j++){
            if(i*j%2019==0){
                cout << '0' << endl;
                return 0;
            }
            min = i*j%2019 < min ? i*j%2019 : min;
        }
    }
    cout << min << endl;
    return 0;
}