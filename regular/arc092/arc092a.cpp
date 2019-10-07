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

    int n, a, b, c, d;
    vector<pair<int, int>> red, blue;
    cin >> n;
    rep(i, n){
        cin >> a >> b;
        red.push_back(make_pair(a, b));
    }
    rep(i, n){
        cin >> c >> d;
        blue.push_back(make_pair(c, d));
    }

    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());

    int res = 0;
    int used[1000];
    rep(i, n){
        used[i] = 0;
    }
    for(auto const& r : red){
        rep(i, n){
            if(used[i]) continue;
            if(r.first >= blue[i].first) continue;
            if(r.second < blue[i].second){
                res++;
                used[i] = 1;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}