#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
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
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    ll cnt[5];
    string s;

    rep(i, 5){
        cnt[i] = 0;
    }

    cin >> n;
    rep(i, n){
        cin >> s;
        if(s[0] == 'M') cnt[0]++;
        if(s[0] == 'A') cnt[1]++;
        if(s[0] == 'R') cnt[2]++;
        if(s[0] == 'C') cnt[3]++;
        if(s[0] == 'H') cnt[4]++;
    }

    ll res = 0;
    rep(i, 3){
        reps(j, i+1, 4){
            reps(k, j+1, 5){
                res += cnt[i]*cnt[j]*cnt[k];
                //cout << i << " " << j << " " << k << endl;
                //cout << cnt[i] << " " << cnt[j] << " " << cnt[k] << endl << endl;
            }
        }
    }

    cout << res << endl;

    return 0;
}