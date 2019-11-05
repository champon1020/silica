#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define inf 1e18
using namespace std;


// from
class Fanctions {
  public:
    template<typename T> 
    T gcd(T a, T b){
        if(b==0) return a; 
        return gcd(b, a%b);
    }

    template<typename T>
    T lcm(T a, T b){
        return a*(b/gcd(a, b));
    }

    template<typename T>
    T keta(T num){
        T k=0; 
        while(num>0){ 
            num/=10;
            k++;
        }
        return k;
    }
};
// to


int main(){
    Gcd g;
    cout << g.keta(100) << endl;    // 3
    cout << g.gcd(24, 36) << endl;  // 12
    cout << g.lcm(3, 4) << endl;    // 12
    return 0;
}
