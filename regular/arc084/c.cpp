#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


ll bcnt[100010], acnt[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, tmp;
    vector<ll> a, b, c;
    cin >> n;
    rep(i, 3*n){
        cin >> tmp;
        if(i < n) a.push_back(tmp);
        else if(i < 2*n) b.push_back(tmp);
        else c.push_back(tmp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    rep(i, n){
        auto itr = upper_bound(c.begin(), c.end(), b[i]);
        int ind = distance(c.begin(), itr);
        if(ind != c.size()){
            bcnt[i] = c.size()-ind;
        }else{
            bcnt[i] = 0;
        }
    }

    repr(i, n-1, 1){
        bcnt[i-1] += bcnt[i];
    }

    rep(i, n){
        auto itr = upper_bound(b.begin(), b.end(), a[i]);
        int ind = distance(b.begin(), itr);
        if(ind != b.size()){
            acnt[i] = bcnt[ind];
        }else{
            acnt[i] = 0;
        }
    }

    ll res = 0;
    rep(i, n){
        res += acnt[i];
        //cout << acnt[i] << endl;
    }

    cout << res << endl;

    return 0;
}
