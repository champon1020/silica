#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, d;
    double x[10][10];
    cin >> n >> d;
    for(Int i=0; i<n; i++){
        for(Int j=0; j<d; j++){
            cin >> x[i][j];
        }
    }

    Int sum = 0;
    for(Int i=0; i<n-1; i++){
        for(Int k=i+1; k<n; k++){
            double dis = 0.0;
            for(Int j=0; j<d; j++){
                dis += pow((x[i][j]-x[k][j]), 2);
            }
            dis = sqrt(dis);
            if(floor(dis) == dis){
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}