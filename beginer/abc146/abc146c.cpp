#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename T> inline bool chmax(T &a, T b){ if(a<b) a=b; return a<b; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a) a=b; return b<a; }
template<typename T> void vdeb(T v){
    cout << "#vector set debug" << endl;
    for(auto vv : v) cout << vv << " ";
    cout << endl;
}
template<typename T1, typename T2> void adeb(T1 arr[], T2 n){
    cout << "#adebug" << endl;
    for(int i=0; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}
template<typename T1> void mdeb(T1 mp){
    cout << "#map pair debug" << endl;
    for(auto const& m : mp) cout << m.first sp m.second << endl;
}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
void ans(bool b){ cout << (b ? "Yes" : "No") << endl; }
void ans2(bool b){ cout << (b ? "YES" : "NO") << endl; }
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};


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
    ll powpow(T1 num1, T2 num2){
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
    ll ceil(T1 a, T2 b){
        return (a+b-1)/b;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, x;
    cin >> a >> b >> x;
    Math mt;

    ll res = 0;
    ll l = 0;
    ll r = 1e9;
    if(a*r + b*mt.keta(r) <= x) res = r;
    while(l + 1 < r){
        //cout << l sp r << endl;
        ll c = (l+r)/2;
        ll money = a*c + b*mt.keta(c);
        if(money <= x){
            res = max(res, c);
            l = c;
        }else{
            r = c;
        }
    }

    cout << res << endl;

    return 0;
}
