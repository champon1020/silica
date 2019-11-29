#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    double w, h, x, y;
    cin >> w >> h >> x >> y;

    int ans = x==w/2.0 && y==h/2.0;
    printf("%.10lf %d", w*h/2, ans);
    return 0;
}