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

    int n;
    string s;
    cin >> n >> s;
    int slen = s.length();

    int white = 0, black = 0;
    int wb;
    bool flg;
    if(s[0] == '.'){
        flg = true;
        wb = 1<<1;
    }else{
        flg = false;
        wb = 1<<0;
        black++;
    }

    vector<int> white_v, black_v;
    reps(i, 1, slen-1){
        if(flg && s[i] == '#'){
            flg = false;
            wb = 1<<0;
            black++;
            continue;
        }
        if(flg) continue;
        if(s[i] == '.'){
            if(wb & 1<<1){
                white++;
            }else{
                wb = 1<<1;
                white++;
            }
        }else{
            if(wb & 1<<0){
                black++;
            }else{
                white_v.push_back(white);
                black_v.push_back(black);
                wb = 1<<0;
                black=1, white=0;
            }
        }
    }
    if(s[slen-1] == '.'){
        white_v.push_back(white);
        black_v.push_back(black);
    }

    int w_sum[200010];
    int b_sum[200010];
    int sz = black_v.size();
    w_sum[sz] = b_sum[0] = 0;
    rep(i, sz){
        b_sum[i+1] = b_sum[i] + black_v[i];
        w_sum[sz-i-1] = w_sum[sz-i] + white_v[sz-i-1];
    }

    ll res = inf;
    reps(i, 0, sz){
        ll sum = w_sum[i] + b_sum[i];
        chmin(res, sum);
    }

    cout << res << endl;

    // vdeb(white_v);
    // vdeb(black_v);
    //adeb(w_sum, sz);
    //adeb(b_sum, sz);

    return 0;
}
