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
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> void vdebug(vector<T> v){ cout << "vdebug" << endl; for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ cout << "adebug" << endl; reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
template<typename T1, typename T2> void mdebug(map<T1, T2> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebug(multimap<T1, T2> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mdebugr(map<T1, T2, greater<T1>> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebugr(multimap<T1, T2, greater<T1>> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


ll mod = 1e9+7;

template<typename T>
class Comb {
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
                comb[i][j] %= mod;
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

    ll x, y;
    cin >> x >> y;

    int right_two = 0;
    int up_two = 0;

    int i=0, j=0;
    bool res = false;
    while(i <= x && j <= y){
        if(i == x && j == y){
            res = true;
            break;
        }
        if(x-i >= y-j){
            i += 2;
            j++;
            right_two++;
        }else{
            i++;
            j += 2;
            up_two++;
        }
    }

    if(!res){
        cout << 0 << endl;
        return 0;
    }

    Comb<ll> comb;
    comb.build_fact(right_two + up_two + 1);

    cout << comb.fact[right_two+up_two] * (comb.finv[right_two] * comb.finv[up_two] % mod) % mod << endl;

    return 0;
}
