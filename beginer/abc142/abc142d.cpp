#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


Int gcd(Int a, Int b){
    Int p, q, r, s;
    p = a > b ? a : b;
    q = a > b ? b : a;
    while(true){
        s = p/q;
        r = p%q;
        if(r==0){
            break;
        }else{
            p = q;
            q = r;
        }
    }
    return q;
}

Int findFactors(Int num){
    Int cnt = 1;
    bool flg = true;
    
    Int j=2;
    while(j*j <= num){
        if(num%j==0){
            cnt++;
            while(num%j==0) num/=j;
        }
        j++;
    }
    if(num > 1){
        cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int a, b;
    cin >> a >> b;

    Int g = gcd(a, b);
    Int ans = findFactors(g);

    // for(auto nn : n){
    //     cout << nn << endl;
    // }

    cout << ans << endl;

    return 0;
}