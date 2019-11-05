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
template<typename T1, typename T2> void mldebug(multimap<T1, T2> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mdebugr(map<T1, T2, greater<T1>> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebugr(multimap<T1, T2, greater<T1>> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


vector<ll> scare;
vector<ll> rest;
int ind = 0;

void rec(ll el){
    ll num = el - rest[ind];
    //cout << "num, el: " sp num sp el << endl;
    if(num > 0){
        rest[ind] = 0;
        ind++;
        rec(num);
    }else{
        rest[ind] -= el;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll a[100010], b[100010];
    ll asum=0, bsum = 0;
    cin >> n;
    rep(i, n){
        cin >> a[i];
        asum += a[i];
    }
    rep(i, n){
        cin >> b[i];
        bsum += b[i];
    }

    if(bsum > asum){
        cout << -1 << endl;
        return 0;
    }

    rep(i, n){
        if(a[i] < b[i]){
            scare.push_back(b[i] - a[i]);
        }else{
            if(a[i] != b[i]){
                rest.push_back(a[i] - b[i]);
            }
        }
    }

    sort(all(rest), greater<ll>());

    if(scare.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    //vdebug(rest);

    for(auto const& e : scare){
        if(rest[ind] == 0) ind++;
        if(e <= rest[ind]){
            rest[ind] -= e;
        }else{
            rec(e);
        }
    }

    //vdebug(rest);
    //cout << scare.size() sp ind << endl;

    cout << scare.size() + ind + 1 << endl;

    return 0;
}
