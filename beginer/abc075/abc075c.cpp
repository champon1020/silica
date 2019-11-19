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
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    vector<int> g[100];
    vector<pair<int, int>> edges;
    set<int> visit;
    ll cnt = 0;
    int start;

    cin >> n >> m;
    rep(i, m){
        cin >> a >> b;
        if(i == 0) start = a;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }

    int check1, check2;

    function<void(int)> dfs = [&](int s){
        visit.insert(s);
        for(auto const& e : g[s]){
            if(visit.find(e) != visit.end()) continue;
            if(e == check1 && s == check2) continue;
            if(e == check2 && s == check1) continue;
            dfs(e);
        }
    };

    rep(i, m){
        visit.clear();
        check1 = edges[i].first;
        check2 = edges[i].second;
        dfs(start);
        if(visit.size() < n) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
