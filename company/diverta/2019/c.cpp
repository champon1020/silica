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

    int n;
    string sin;
    int front_b = 0;
    int back_a = 0;
    int both = 0;
    int cnt = 0;

    cin >> n;
    rep(i, n){
        cin >> sin;
        reps(i, 1, sin.length()-1){
            if(sin[i-1] == 'A' && sin[i] == 'B') cnt++;
        }

        if(sin[0] == 'B' && sin[sin.length()-1] == 'A') both++;
        else{
            if(sin[0] == 'B') front_b++;
            if(sin[sin.length()-1] == 'A') back_a++;
        }
    }

    if(both > 0){
        if(both >= 1){
            if(front_b > 0){
                front_b--;
                cnt++;
            }
            if(back_a > 0){
                back_a--;
                cnt++;
            }
        }
        if(both > 1){
            cnt += both-1;
        }
    }

    if(front_b > 0 && back_a > 0){
        cnt += min(front_b, back_a);
    }

    cout << cnt << endl;

    return 0;
}
