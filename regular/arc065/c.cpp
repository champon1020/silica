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


string s;
int len;

bool rec(ll e){
    if(s[e] == 'd'){
        if(e+5 == len && s.substr(e, 5) == "dream") return true;
        if(e+7 == len && s.substr(e, 7) == "dreamer") return true;
        if(e+5 > len) return false;
        else {
            bool b1=false, b2=false;
            if(s.substr(e, 5) == "dream") b1 = rec(e+5);
            if(s.substr(e, 7) == "dreamer") b2 = rec(e+7);
            return b1 || b2;
        }
    }else if(s[e] == 'e'){
        if(e+5 == len && s.substr(e, 5) == "erase") return true;
        if(e+6 == len && s.substr(e, 6) == "eraser") return true; 
        if(e+5 > len) return false;
        else {
            bool b1=false, b2=false;
            if(s.substr(e, 5) == "erase") b1 = rec(e+5);
            if(s.substr(e, 6) == "eraser") b2 = rec(e+6);
            return b1 || b2;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    len = s.length();

    bool res = rec(0);
    ans2(res);

    return 0;
}
