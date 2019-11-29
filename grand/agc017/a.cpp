#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
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


template<typename T>
class Comb {
    ll mod = 1e9+7;
  public:
    vector<vector<T>> comb;
    vector<T> fact;
    vector<T> finv;
    vector<T> inv;
    Comb(){};

    void build_comb(int n){
        comb.assign(n, vector<T>(n, 0));
        rep(i, n){
            comb[i][0] = 1;
            comb[i][i] = 1;
        }
        reps(i, 1, n-1){
            reps(j, 1, i-1){
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
                //comb[i][j] %= mod;
            }
        }
    }

    void build_fact(ll n){
        inv.assign(n+1, 0);
        fact.assign(n+1, 0);
        finv.assign(n+1, 0);
        fact[0] = fact[1] = finv[0] = finv[1] = 1;
        inv[1] = 1;
        reps(i, 2, n){
            fact[i] = fact[i-1]*i % mod;
            inv[i] = mod - inv[mod%i]*(mod/i)%mod;
            finv[i] = finv[i-1]*inv[i]%mod;
        }
    }

    T result(int n, int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return comb[n][k];
    }

    T result_fact(ll n, ll k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fact[n]*(finv[k]*finv[n-k]%mod)%mod;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p, a[110], cnt[2];
    cnt[0] = 0, cnt[1] = 0;
    cin >> n >> p;
    rep(i, n){
        cin >> a[i];
        cnt[a[i]%2]++;
    }

    Comb<ll> c;
    c.build_comb(n+1);

    ll sum = 0;
    if(p == 0){
        reps(i, 0, cnt[1]){
            if(i%2 == 1) continue;
            reps(j, 0, cnt[0]){
                sum += c.result(cnt[1], i)*c.result(cnt[0], j);
            }
        }
    }else{
        reps(i, 0, cnt[1]){
            if(i%2 == 0) continue;
            reps(j, 0, cnt[0]){
                sum += c.result(cnt[1], i)*c.result(cnt[0], j);
            }
        }
    }

    cout << sum << endl;

    return 0;
}
