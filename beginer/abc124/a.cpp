#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int a, b;
    cin >> a >> b;
    Int sum = 0;
    for(Int i=0; i<2; i++){
        if(a > b){
            sum+=a;
            a--;
        }else{
            sum+=b;
            b--;
        }
    }
    cout << sum << endl;

    return 0;
}