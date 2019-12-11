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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll k, n;
    string s, t;
    cin >> k;
    rep(i, k){
        cin >> n >> s >> t;
        map<char, int> mp;
        rep(i, n){
            mp[s[i]]++;
            mp[t[i]]++;
        }
        bool result = true;
        for(auto const& e : mp){
            if(e.second % 2 == 1) result = false;
        }
        ans(result);
        if(!result) continue;

        int last_ind = -1;
        vector<pair<int, int>> res;
        rep(i, n){
            if(s[i] == t[i]) continue;
            if(last_ind == -1){
                last_ind = i;
                continue;
            }   
            if(s[i] == s[last_ind]){
                res.push_back(make_pair(i+1, last_ind+1));
                swap(s[i], t[last_ind]);
                if(s[i] != t[i]) last_ind = i;
                else last_ind = -1;
            }
            if(s[last_ind] == t[i]){
                res.push_back(make_pair(i+1, i+1));
                res.push_back(make_pair(i+1, last_ind+1));
                swap(s[i], t[i]);
                swap(s[i], t[last_ind]);
                if(s[i] != t[i]) last_ind = i;
                else last_ind = -1;
            }
        }
        cout << res.size() << endl;
        for(auto const& e : res){
            cout << e.first sp e.second << endl;
        }
    }

    return 0;
}
