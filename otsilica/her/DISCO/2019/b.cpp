#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename T> inline bool chmax(T &a, T b){ if(a<b) a=b; return a<b; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a) a=b; return b<a; }
template<typename T> void vdeb(vector<T> v){
    cout << "#vdebug" << endl;
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
    cin >> n;

    ll cnt = 0;
    double x=1.0, y=1.0;

    int visit[110][110];
    Fill(visit, 0);

    function<void(double, double)> dfs = [&](double x, double y){
        if(n%2==0 && y > -x + double(n/2)) return;
        if(n%2==1 && y > -x + double(n/2) - 0.5) return;

        visit[int(x)][int(y)] = 1;
        cnt++;

        //cout << x sp y << endl;
        
        rep(i, 2){
            double dlx = x + dx[i];
            double dly = y + dy[i];
            if(visit[int(dlx)][int(dly)]) continue;
            dfs(dlx, dly);
        }
    };
    
    dfs(x, y);

    ll res = 0;
    if(n%2 == 1){
        double x = 0.5, y = 0.5;
        ll bufcnt = 0;
        while(y <= -x + double(n/2) - 0.5){
            bufcnt++;
            y += 1.0;
        }
        res = cnt*4 + bufcnt*4 + 1;
    } else res = cnt*4;
    

    cout << res << endl;

    return 0;
}