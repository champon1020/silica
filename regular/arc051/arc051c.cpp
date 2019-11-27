#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define ceil(a, b) (a+b-1)/b
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

    double x1, y1, r;
    double x2, y2, x3, y3;
    cin >> x1 >> y1 >> r;
    cin >> x2 >> y2 >> x3 >> y3;

    double lu = sqrt(pow(x1 - x2, 2) + pow(y1 - y3, 2));
    double ld = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double ru = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double rd = sqrt(pow(x1 - x3, 2) + pow(y1 - y2, 2));

    //cout << lu sp ld sp ru sp rd << endl;

    bool blue = true, red = true;
    if(x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3) red = false;
    if(lu <= r && ld <= r && ru <= r && rd <= r) blue = false;

    ans2(red);
    ans2(blue);

    return 0;
}
