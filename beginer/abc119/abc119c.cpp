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


int n, aa, bb, cc;
    int l[10];

ll rec(int pos, int a, int b, int c){
    if(pos == n){
        if(min(min(a, b), c) > 0){
            ll res = abs(aa-a)+abs(bb-b)+abs(cc-c);
            return res-30;
        }else return inf;
    }

    ll var1 = rec(pos+1, a, b, c);
    ll var2 = rec(pos+1, a+l[pos], b, c)+10;
    ll var3 = rec(pos+1, a, b+l[pos], c)+10;
    ll var4 = rec(pos+1, a, b, c+l[pos])+10;

    return min(min(var1, var2), min(var3, var4));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> aa >> bb >> cc;
    rep(i, n){
        cin >> l[i];
    }

    cout << rec(0, 0, 0, 0) << endl;

    return 0;
}
