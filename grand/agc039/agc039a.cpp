#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e10
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

    string s;
    ll k;
    cin >> s;
    cin >> k;
    
    int len = s.length();

    if(len == 1){
        cout << k/2 << endl;
        return 0;
    }

    ll cnt = 0;
    rep(i, len-1){
        if(s[i] == s[i+1]){
            if(i == len-2){
                if(s[0] == s[len-1]){
                    s[i+1] = '?';
                    cnt++;
                }else{
                    s[i] = '?';
                    cnt++;
                }
            }else if(i+2 < s.length() && s[i] == s[i+2]){
                cnt++;
                s[i+1] = '?';
            }else{
                cnt++;
                s[i] = '?';
            }
        }
    }
    ll res = cnt*k;
    if(s[0] == s[len-1]){
        res += k-1;
    }
 
    cout << res << endl;
    //cout << s << endl;

    return 0;
}