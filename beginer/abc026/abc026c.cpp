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

    int n, tmpb;
    vector<pair<int, int>> b;
    vector<int> t[100];
    cin >> n;
    reps(i, 2, n){
        cin >> tmpb;
        b.push_back(make_pair(tmpb, i));
        t[tmpb].push_back(i);
    }

    sort(all(b), greater<pair<int, int>>());

    int res[100];
    Fill(res, 1);
    int visit[100];
    Fill(visit, 0);
    for(auto const& bb : b){
        if(visit[bb.second]) continue;
        int parent = bb.first;
        int maxi = -1;
        int mini = 1e6;
        for(auto const& e : t[parent]){
            chmax(maxi, res[e]);
            chmin(mini, res[e]);
            visit[e] = 1;
        }
        //cout << bb.second sp maxi sp mini << endl;
        res[parent] = maxi + mini + 1;
    }

    cout << res[1] << endl;

    return 0;
}
