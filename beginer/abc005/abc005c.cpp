#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<lli>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> bool chmax(T &a, T &b){ if(a<b) { a=b; return 1; }}
template<typename T> bool chmin(T &a, T &b){ if(b<a) { a=b; return 1; }}
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

    int t, n, m, tmpint;
    vector<int> a, b;
    cin >> t >> n;
    rep(i, n){
        cin >> tmpint;
        a.push_back(tmpint);
    }
    cin >> m;
    rep(i, m){
        cin >> tmpint;
        b.push_back(tmpint);
    }

    int sold[100];
    rep(i, n){
        sold[i] = 0;
    }
    for(auto bb : b){
        bool flg = false;
        rep(i, n){
            if(sold[i]) continue;
            if(a[i] <= bb && bb <= a[i]+t){
                flg = true;
                sold[i] = 1;
                break;
            }
        }
        if(!flg){
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

    return 0;
}