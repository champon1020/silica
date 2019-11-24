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
    cin >> n;
    vector<int> g[100010];
    vector<pair<int, int>> vp;
    int a, b;
    rep(i, n-1){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        vp.push_back(make_pair(a, b));
    }

    int k=0;
    int colors[100010];
    map<pair<int, int>, int> mp;
    queue<int> q;
    q.push(1);
    int visit[100010];
    visit[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(k < g[v].size()) k = g[v].size();
        int color = 1;
        for(auto const& e : g[v]){
            if(visit[e]) continue;
            if(colors[v] == color) color++;
            colors[e] = color;
            mp[make_pair(e, v)] = mp[make_pair(v, e)] = color++;
            visit[e] = 1;
            q.push(e);
        }
    }

    cout << k << endl;
    rep(i, n-1){
        cout << mp[vp[i]] << endl;

    }

    return 0;
}
