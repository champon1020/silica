#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define ceil(a, b) (a+b-1)/b
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
    ll ceill(T1 a, T2 b){
        return (a+b-1)/b;
    }
};


class B {
public:
	void solve(std::istream& cin, std::ostream& cout) {
        int b[10], n;
        Math mt;
        ll tmp;
        vector<ll> a;
        rep(i, 10){
            cin >> b[i];
        }
        cin >> n;
        rep(i, n){
            cin >> tmp;
            a.push_back(tmp);
        }

        function<bool(ll const&, ll const&)> comp = [&](ll const& n1, ll const& n2){
            if(mt.keta(n1) != mt.keta(n2)) return mt.keta(n1) < mt.keta(n2);
            int keta = mt.keta(n1);
            while(keta > 0){
                int num1 = n1 / mt.powl(10, keta-1) % 10;
                int num2 = n2 / mt.powl(10, keta-1) % 10;
                int marker1, marker2;
                rep(i, 10){
                    if(num1 == b[i]) marker1 = i;
                    if(num2 == b[i]) marker2 = i;
                }
                if(marker1 != marker2) return marker1 < marker2;
                keta--;
                //cout << n1 sp n2  sp num1 sp num2 << endl;
            }
            return true;
        };

        sort(all(a), comp);

        rep(i, n) {
            cout << a[i] << endl;
        }
	}
};
