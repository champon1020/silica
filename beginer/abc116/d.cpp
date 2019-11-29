#include <bits/stdc++.h>
#define ll long long
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
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
template<typename T> T keta(T num){ T k=0; while(num>0){ num/=10; k++; } return k; }
template<typename T> void vdebug(vector<T> v){ cout << "vdebug" << endl; for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ cout << "adebug" << endl; reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
template<typename T1, typename T2> void mdebug(map<T1, T2> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mdebugr(map<T1, T2, greater<T1>> mp){ cout << "mdebugr" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebug(multimap<T1, T2> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebugr(multimap<T1, T2, greater<T1>> mp){ cout << "mldebugr" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, tin, din;
    multimap<ll, ll, greater<ll>> dt;
    cin >> n >> k;
    rep(i, n){
        cin >> tin >> din;
        dt.insert(make_pair(din, tin));
    }

    int cnt = 0;
    ll res = 0;
    priority_queue<pair<ll, ll>> rest;
    priority_queue<
        pair<ll, ll>, 
        vector<pair<ll, ll>>, 
        greater<pair<ll, ll>>
    > used;

    map<ll, ll> used_t;
    for(auto const& e : dt){
        if(cnt >= k){
            rest.push(make_pair(e.first, e.second));
        }else{
            res += e.first;
            used.push(make_pair(e.first, e.second));
            used_t[e.second]++;
            cnt++;
        }
    }

    //cout << used_t.size() << endl;

    res += used_t.size()*used_t.size();

    //cout << res << endl;

    vector<ll> maxi;
    maxi.push_back(res);
    while(!rest.empty() && !used.empty()){
        pair<ll, ll> rest_top = rest.top();
        pair<ll, ll> used_top = used.top();

        if(used_t[used_top.second] == 1){
            used.pop();
            continue;
        }
        
        if(used_t.find(rest_top.second) == used_t.end()){
            res -= used_t.size()*used_t.size();
            res -= used_top.first;

            //cout << res sp used_top.first sp used_t.size() <<  endl;
            //mdebug(used_t);

            used_t[rest_top.second]++;
            res += used_t.size()*used_t.size();
            res += rest_top.first;

            maxi.push_back(res);
            used_t[used_top.second]--;
            used.pop();
            used.push(rest_top);

            //cout << res << endl;
        }

        rest.pop();
    }

    sort(all(maxi), greater<ll>());

    cout << maxi[0] << endl;

    return 0;
}
