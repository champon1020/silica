#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
ll keta(ll num){ ll k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, q, tmp;
    vector<ll> s, t, x;

    cin >> a >> b >> q;
    rep(i, a){
        cin >> tmp;
        s.push_back(tmp);
    }
    rep(i, b){
        cin >> tmp;
        t.push_back(tmp);
    }
    rep(i, q){
        cin >> tmp;
        x.push_back(tmp);
    }

    vector<ll> scand;
    vector<ll> tcand;
    rep(i, q){
        ll sind = distance(s.begin(), lower_bound(all(s), x[i]));
        ll tind = distance(t.begin(), lower_bound(all(t), x[i]));
        if(sind == s.size()){
            sind = s.size()-1;
            scand.push_back(s[sind]);
        }else if(sind == 0){
            scand.push_back(s[sind]);
        }else{
            scand.push_back(s[sind]);
            scand.push_back(s[sind-1]);
        }

        if(tind == t.size()){
            tind = t.size()-1;
            tcand.push_back(t[tind]);
        }else if(tind == 0){
            tcand.push_back(t[tind]);
        }else{
            tcand.push_back(t[tind]);
            tcand.push_back(t[tind-1]);
        }

        ll res = inf;
        rep(k, scand.size()){
            rep(j, tcand.size()){
                chmin(res, abs(x[i]-scand[k])+abs(scand[k]-tcand[j]));
                chmin(res, abs(x[i]-tcand[j])+abs(tcand[j]-scand[k]));
            }
        }
        cout << res << endl;
        scand.clear();
        tcand.clear();
    }

    return 0;
}
