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
    int t[10][10];
    cin >> n >> k;
    rep(i, n){
        rep(j, k){
            cin >> t[i][j];
        }
    }

    ll sum = 0;
    bool res = true;
    rep(i, k){
        sum ^= t[0][i];
        if(n >= 2){
            rep(j, k){
                sum ^= t[1][j];
                if(n >= 3){
                    rep(l, k){
                        sum ^= t[2][l];
                        if(n >= 4){
                            rep(m, k){
                                sum ^= t[3][m];
                                if(n >= 5){
                                    rep(o, k){
                                        sum ^= t[4][o];
                                        if(sum == 0) res = false;
                                        sum ^= t[4][o];
                                    }
                                }
                                if(n <= 4 && sum == 0) res = false;
                                sum ^= t[3][m];
                            }
                        }
                        if(n <= 3 && sum == 0) res = false;
                        sum ^= t[2][l];
                    }
                }
                if(n <= 2 && sum == 0) res = false;
                sum ^= t[1][j];
            }
        }
        if(n <= 1 && sum == 0) res = false;
        sum ^= t[0][i];
    }

    if(!res) cout << "Found" << endl;
    else cout << "Nothing" << endl;

    return 0;
}
