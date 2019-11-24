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
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, l, r, s, t;
    int d, k;
    vector<pair<ll, ll>> lr, st;
    cin >> n >> d >> k;
    rep(i, d){
        cin >> l >> r;
        lr.push_back(make_pair(l, r));
    }
    rep(i, k){
        cin >> s >> t;
        st.push_back(make_pair(s, t));
    }

    int res[110], complete[110];
    Fill(res, 0);
    Fill(complete, 0);
    for(auto const& e : lr){
        ll l = e.first;
        ll r = e.second;
        reps(i, 1, k){
            if(complete[i]) continue;
            if(l <= st[i-1].first && st[i-1].first <= r){
                if(st[i-1].first < st[i-1].second){
                    st[i-1].first = r;
                    if(st[i-1].second <= r) complete[i] = 1;
                }else{
                    st[i-1].first = l;
                    if(st[i-1].second >= l) complete[i] = 1;
                }
            }
            res[i]++;
        }
    }

    reps(i, 1, k){
        cout << res[i] << endl;
    }

    return 0;
}
