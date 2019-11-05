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
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int slen = s.length();

    vector<ll> v;
    ll cnt = 1;
    reps(i, 1, slen-1){
        if(s[i] == s[i-1])cnt++;
        else{
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);

    int marker = s[0] == '<' ? 0 : 1;

    int num;
    ll sum = 0;
    if(s[0] == '>'){
        num = v[0];
        sum += (num*(num+1))/2;
    }

    reps(i, 1, v.size()-1){
        if(i%2 == marker) continue;
        if(v[i] > v[i-1]){
            sum += (v[i]*(v[i]+1))/2;
            sum += (v[i-1]*(v[i-1]-1))/2;
        }else{
            sum += (v[i]*(v[i]-1))/2;
            sum += (v[i-1]*(v[i-1]+1))/2;
        }

        //cout << sum << endl;
    }

    if(s[slen-1] == '<'){
        num = v[v.size()-1];
        sum += (num*(num+1))/2;
    }

    vdebug(v);
    cout << sum << endl;

    return 0;
}
