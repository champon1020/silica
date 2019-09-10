#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    Int n;
    cin >> n;
    vector<Int> x(n), y(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    for(int i=0; i<n; i++){
        Int gx = x[i];
        Int gy = y[i];
        for(int k=0; k<4; k++){
            {
                Int nx = -gy;
                Int ny = gx;
                gx = nx;
                gy = ny;
            }

            auto dot = [](Int x1, Int y1, Int x2, Int y2){ return x1*x2 + y1*y2; };
            auto cross = [](Int x1, Int y1, Int x2, Int y2){ return x1*y2 - x2*y1; };
            
        }
    }

    return 0;
}