#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e10
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<lli>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> bool chmax(T &a, T &b){ if(a<b) { a=b; return 1; }}
template<typename T> bool chmin(T &a, T &b){ if(b<a) { a=b; return 1; }}
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


class Bit{
    int n, bit[200001];

public:
    void init(int n_){
        n = n_;
        rep(i, n+1) bit[i] = 0;
    }

    int sum(int i){
        int val = 0;
        while(i > 0){
            val += bit[i];
            i -= i&-i;
        }
        return val;
    }

    void add(int i, int x){
        while(i <= n){
            bit[i] += x;
            i += i&-i;
        }
    }

    void update(int i, int x){
        int diff = x - bit[i];
        // while(i <= n){
        //     bit[i] += diff;
        //     i += i&-i;
        // }
        for (int k = i; k < n; k |= k + 1) {
            if (bit[k] < x)
            bit[k] = x;
        }
    }

    int maximum(int i){
        int res = -1;
        for(int k=i-1; k>=0; k--){
            res = max(res, bit[k]);
            res = max(res, bit[(k-1)/2]);
        }
        return res;
    }

    int operator[](int i){
        return bit[i];
    }
};


bool comparable(pair<int, int> p1, pair<int, int> p2){
    if(p1.first != p2.first) return p1.first < p2.first;
    else return p1.second > p2.second;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w, h;
    vector<pair<int, int>> box;
    cin >> n;
    rep(i, n){
        cin >> w >> h;
        box.push_back(make_pair(h, w));
    }

    sort(box.begin(), box.end(), comparable);

    Bit bit;
    bit.init(100001);
    int dp[100001];
    rep(i, n){
        dp[i] = bit.maximum(box[i].second) + 1;
        bit.update(box[i].second, dp[i]);
        //cout << box[i].second << " " << bit[box[i].second] << " " << dp[i] << endl;
        // reps(i, 1, 9){
        //     cout << bit[i] << " ";
        // }
        // cout << endl;
    }

    int res = 0;
    rep(i, n){
        res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}