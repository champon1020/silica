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

    int n;
    ll a[100010];
    cin >> n;
    rep(i, n){
        cin >> a[i];
    }

    ll asum[100010];
    asum[0] = 0;
    rep(i, n){
       asum[i+1] = asum[i] + a[i]; 
    }

    ll sum = 0;
    ll res = 0;
    int flg = 0;
    int zerocnt = 0;
    reps(i, 1, n){
        if(flg == 0){
            if(asum[i] > 0) flg = 1;
            else if(asum[i] < 0) flg = -1;
            else zerocnt++;
            continue;
        }
        if(flg == 1){
            if(asum[i] + sum >= 0){
                res += abs(asum[i] + sum) + 1;
                sum += -abs(asum[i] + sum) - 1;
            }
            flg = -1;
        }else if(flg == -1){
            if(asum[i] + sum <= 0){
                res += abs(asum[i] + sum) + 1;
                sum += abs(asum[i] + sum) + 1;
            }
            flg = 1;
        }
    }

    if(zerocnt > 0){
        res += 2*zerocnt-1;
    }

    //adeb(asum, n);

    cout << res << endl;

    return 0;
}
