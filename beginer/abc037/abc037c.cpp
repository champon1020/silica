#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename T> inline bool chmax(T &a, T b){ if(a<b) a=b; return a<b; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a) a=b; return b<a; }
template<typename T> void vdeb(T v){
    cout << "#vector set debug" << endl;
    for(auto vv : v) cout << vv << " ";
    cout << endl;
}
template<typename T1, typename T2> void adeb(T1 arr[], T2 n){
    cout << "#adebug" << endl;
    for(int i=0; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}
template<typename T1> void mdeb(T1 mp){
    cout << "#map pair debug" << endl;
    for(auto const& m : mp) cout << m.first sp m.second << endl;
}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
void ans(bool b){ cout << (b ? "Yes" : "No") << endl; }
void ans2(bool b){ cout << (b ? "YES" : "NO") << endl; }
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    ll a[100010];
    cin >> n >> k;
    rep(i, n){
        cin >> a[i];
    }

    ll sum = 0;
    if(n <= 2*k){
        reps(i, n-k, k-1){
            sum += a[i] * (n-k+1);
        }
        reps(i, 0, n-k-1){
            sum += a[i] * (i+1);
        }
        repr(i, n-1, k){
            sum += a[i] * (n-i);
        }
    }else{
        reps(i, k-1, n-k){
            sum += a[i] * k;
        }
        reps(i, 0, k-2){
            sum += a[i] * (i+1);
        }
        repr(i, n-1, n-k+1){
            sum += a[i] * (n-i);
        }
    }

    cout << sum << endl;

    return 0;
}
