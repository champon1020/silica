#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, w;
    cin >> h >> w;

    if(w%3 == 0 || h%3 == 0){
        cout << 0 << endl;
        return 0;
    }

    if(h==2 && w==2){
        cout << 1 << endl;
        return 0;
    }

    ll res = inf;

    res = min(w*(h-2*h/3) - w*(h/3), res);
    res = min(h*(w-2*w/3) - h*(w/3), res);

    //cout << res << endl;

    reps(i, 1, h-1){
        ll maxi = 0;
        ll mini = inf;
        maxi = max(w*i, maxi);
        mini = min(w*i, mini);

        maxi = max(w/2 * (h-i), maxi);
        mini = min(w/2 * (h-i), mini);

        maxi = max((w - w/2) * (h-i), maxi);
        mini = min((w - w/2) * (h-i), mini);
        
        res = min(maxi-mini, res);
        //cout << maxi << " " << mini << endl;
        //cout << res << endl;
    }

    //cout << res << endl;

    reps(i, 1, w-1){
        ll maxi = 0;
        ll mini = inf;
        maxi = max(h*i, maxi);
        mini = min(h*i, mini);

        maxi = max(h/2 * (w-i), maxi);
        mini = min(h/2 * (w-i), mini);

        maxi = max((h - h/2) * (w-i), maxi);
        mini = min((h - h/2) * (w-i), mini);
        
        res = min(maxi-mini, res);
        //cout << maxi << " " << mini << endl;
        //cout << res << endl;
    }

    cout << res << endl;

    return 0;
}
