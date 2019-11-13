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
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> void vdebug(vector<T> v){ cout << "vdebug" << endl; for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ cout << "adebug" << endl; reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
template<typename T1, typename T2> void mdebug(map<T1, T2> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebug(multimap<T1, T2> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mdebugr(map<T1, T2, greater<T1>> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebugr(multimap<T1, T2, greater<T1>> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


struct Pair {
    ll sumx, sumy, sumz;
    Pair(ll x, ll y, ll z):sumx(x),sumy(y),sumz(z){};

    Pair add(ll x, ll y, ll z){
        return Pair(sumx + x, sumy + y, sumz + z);
    }

    ll sum(){
        return abs(sumx) + abs(sumy) + abs(sumz);
    }
};

bool compare(Pair p1, Pair p2){
    ll sum1 = abs(p1.sumx) + abs(p1.sumy) + abs(p1.sumz);
    ll sum2 = abs(p2.sumx) + abs(p2.sumy) + abs(p2.sumz);
    return sum1 < sum2;
}

bool compare2(Pair p1, Pair p2, Pair cost){
    cout << p1.sumx sp p1.sumy sp p1.sumz sp cost.sumx sp cost.sumy sp cost.sumz << endl;
    ll sum1 = abs(p1.sumx) + abs(p1.sumy) + abs(p1.sumz);
    ll sum2 = abs(p2.sumx + cost.sumx) + abs(p2.sumy + cost.sumy) + abs(p2.sumz + cost.sumz);
    return sum1 < sum2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    ll x[1010], y[1010], z[1010];
    cin >> n >> m;
    rep(i, n){
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<vector<Pair>> dp;
    dp.assign(1010, vector<Pair>(1010, Pair(0, 0, 0)));

    reps(i, 0, n-1){
        repr(j, m-1, 0){
            if(compare2(dp[i][j], dp[i][j+1], Pair(x[i], y[i], z[i]))){
                dp[i+1][j] = dp[i][j+1].add(x[i], y[i], z[i]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[n][0].sum() << endl;

    // reps(i, 0, n){
    //     repr(j, m, 0){
    //         cout << dp[i][j].sumx << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
