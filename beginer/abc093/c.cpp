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

    vector<int> abc(3);
    cin >> abc[0] >> abc[1] >> abc[2];

    int oddcnt = 0;
    int oddarr[3];

    rep(i, 3){
        if(abc[i]%2 == 1){
            oddcnt++;
            oddarr[i] = 1;
        }else{
            oddarr[i] = 0;
        }
    }

    int res = 0;
    if(oddcnt == 2){
        rep(i, 3){
            if(oddarr[i] == 1) abc[i]++;
        }
        res++;
    }
    if(oddcnt == 1){
        rep(i, 3){
            if(oddarr[i] == 0) abc[i]++;
        }
        res++;
    }

    sort(abc.begin(), abc.end());

    int diff1 = abc[2]-abc[0];
    int diff2 = abc[2]-abc[1];

    while(diff1 > 0){
        diff1 -= 2;
        res++;
    }
    while(diff2 > 0){
        diff2 -= 2;
        res++;
    }

    cout << res << endl;

    return 0;
}