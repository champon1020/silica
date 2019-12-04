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
using lli = long long int;
template<typename T> bool chmax(T &a, T &b){ if(a<b) { a=b; return 1; }}
template<typename T> bool chmin(T &a, T &b){ if(b<a) { a=b; return 1; }}
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T arrdebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    lli n, k;
    char s[100001];
    cin >> n >> k;
    cin >> s;

    vector<int> v;
    if(s[0] == '0') v.push_back(0);
    int cnt = 1;
    rep(i, n-1){
        if(s[i+1] == s[i]){
            cnt++;
        }else{
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);
    if(s[0] == '0') v.push_back(0);

    vector<lli> sum(v.size()+1, 0);
    reps(i, 0, v.size()){
        sum[i+1] = sum[i] + v[i];
    }

    // vdebug(v);
    // vdebug(sum);

    int max=0;
    int l=0;
    while(l < sum.size()){
        int r = l+2*k+1;
        if (r >= sum.size()){
            r = sum.size()-1;
        }
        if(max < sum[r]-sum[l]){
            max = sum[r]-sum[l];
        }
        l+=2;
    }
    cout << max << endl;

    return 0;
}