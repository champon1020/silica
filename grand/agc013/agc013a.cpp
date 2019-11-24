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
    vector<ll> a;
    ll tmpa;
    cin >> n;
    reps(i, 0, n-1){
        cin >> tmpa;
        a.push_back(tmpa);
    }

    int itr = 0;
    while(itr < a.size()-1){
        if(a[itr] == a[itr+1]){
            a.erase(a.begin() + itr);
        }else itr++;
    }

    // vdeb(a);
    // cout << a.size() << endl;

    ll cnt = 0;
    int flg[100010];
    Fill(flg, 0);
    reps(i, 1, n-2){
        if(a[i-1] < a[i] && a[i] > a[i+1]){
            if(!flg[i-1]){
                flg[i] = 1;
                cnt++;
            }
        }
        if(a[i-1] > a[i] && a[i] < a[i+1]){
            if(!flg[i-1]){
                flg[i] = 1;
                cnt++;
            }
        }
        //cout << cnt sp i << endl;
    }

    cout << cnt+1 << endl;

    return 0;
}
