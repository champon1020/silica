#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
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

// 各処理の計算量　O(log(n))
// 初期化の計算量 O(n)
const int MAX = 1<<17;

class SegmentTree {
    // nは葉の数（オリジナル配列の要素数）
    // datはセグメント木本体
    ll n, dat[2*MAX-1];

public:
    // 初期化
    // 葉の枚数nnに対して 2^nn-1 個のノードが必要
    SegmentTree(ll nn){
        n = 1;
        while(n < nn) n*=2;
        rep(i, 2*n-1) dat[i] = inf;
    }

    // k番目をaに変更
    void update(ll k, ll a){
        // 葉以外のノードがn-1個あるから
        k += n-1;
        dat[k] = a;

        // 葉を更新して，上まで登っていく
        while(k > 0){
            // 親要素に移動
            k = (k-1)/2;
            // 親要素は子要素の最小値
            //（最大値または区間の和でも構わない）
            // 子要素は 2k+1 or 2k+2 でアクセス可能（二分木）
            dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
        }
    }

    // [a, b) の最小値を求める
    // 範囲に関して次の3パターン
    // 1: 交差していない ---> return inf
    // 2: 完全に含む ---> return 節点の値
    // 3: その他 ---> 再帰的に計算
    // kは節点番号 / l,rは節点が対応づいている範囲
    ll query(ll a, ll b, ll k, ll l, ll r){
        // 交差していない
        if(r <= a || b <= l) return inf;

        // 完全に含む
        if(a <= l && r <= b) return dat[k];
        // その他
        else{
            // 左子ノード
            ll vl = query(a, b, k*2+1, l, (l+r)/2);
            // 右子ノード
            ll vr = query(a, b, k*2+2, (l+r)/2, r);
            // 2つの最小値
            return min(vl, vr);
        }
    }

    ll operator[](int i){
        return dat[i + n - 1];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}