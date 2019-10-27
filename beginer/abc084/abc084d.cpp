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
#define sp << " " <<
#define enl << endl
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
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

    int res[100010];
    res[2] = 1;

    reps(i, 3, 100000){
        res[i] = 0;
        if(i%2 == 0) continue;
        bool flg = true;
        reps(j, 1, sqrt(i)){
            if(i%j == 0 && j!=1){
                flg = false;
                break;
            }
        }
        if(flg){
            res[i] = 1;
        }
    }

    vector<int> v;
    reps(i, 2, 100000){
        if(res[i] == 1 && res[(i+1)/2] == 1){
            v.push_back(i);
        }
    }

    int q;
    cin >> q;

    int l, r;
    rep(i, q){
        cin >> l >> r;
        int cnt = 0;

        auto itrl = lower_bound(all(v), l);
        auto itrr = upper_bound(all(v), r);
        
        cout << distance(v.begin(), itrr) - distance(v.begin(), itrl) << endl;
    }

    return 0;
}
