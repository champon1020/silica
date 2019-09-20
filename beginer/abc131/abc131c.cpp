#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int a, b, c, d;
    cin >> a >> b >> c >> d;

    Int r = 1;
    Int g = c>d ? c : d;
    Int s = c<d ? c : d;
    while(true){
        r = g%s;

        if(r==0){
            break;
        }else{
            g = s;
            s = r;
        }
    }
    
    Int l = c*d/s;
    Int ans1 = b - (b/c + b/d - b/l);
    Int ans2 = a-1 - ((a-1)/c + (a-1)/d - (a-1)/l);
    Int ans = (ans1 - ans2);
    cout << ans << endl;

    return 0;
}