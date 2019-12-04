#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define inf 1e18
using namespace std;


// from
class Math {
    ll mod = 1e9+7;
  public:
    template<typename T1, typename T2> 
    ll gcd(T1 a, T2 b){
        if(b==0) return a; 
        return gcd(b, a%b);
    }

    template<typename T1, typename T2>
    ll lcm(T1 a, T2 b){
        return a*(b/gcd(a, b));
    }

    template<typename T>
    int keta(T num){
        T k=0; 
        while(num>0){ 
            num/=10;
            k++;
        }
        return k;
    }

    template<typename T1, typename T2>
    ll powmod(T1 num1, T2 num2){
        ll res = 1;
        while(num2 > 0){
            res *= num1;
            res %= mod;
            num2--;
        }
        return res%mod;
    }

    template<typename T1, typename T2>
    ll powl(T1 a, T2 b){
        ll res = 1;
        while(b > 0){
            res *= a;
            b--;
        }
        return res;
    }

    template<typename T1, typename T2>
    ll ceill(T1 a, T2 b){
        return (a+b-1)/b;
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
