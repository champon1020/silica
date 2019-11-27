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
    int a[100];
    cin >> n;
    rep(i, n){
        cin >> a[i];
    }

    ll taka_max = -100000;
    rep(i, n){
        pair<ll, int> aoki_max = make_pair(-100000, -1);
        ll aoki_sum;
        rep(j, n){
            if(i == j) continue;
            aoki_sum = 0;
            int start = j < i ? j : i;
            int end = j < i ? i : j;
            reps(k, start, end){
                if(k%2 == start%2) continue;
                aoki_sum += a[k];
            }
            if(aoki_sum > aoki_max.first){
                aoki_max = make_pair(aoki_sum, j);
            }
        }

        ll taka_sum = 0;
        int start = i < aoki_max.second ? i : aoki_max.second;
        int end = i < aoki_max.second ? aoki_max.second : i;
        reps(j, start, end){
            if(j%2 != start%2) continue;
            taka_sum += a[j];
        }

        //cout << i sp aoki_max.second sp aoki_max.first sp taka_sum << endl;
        chmax(taka_max, taka_sum);
    }

    cout << taka_max << endl;

    return 0;
}
