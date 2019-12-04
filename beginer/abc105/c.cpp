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

    ll n;
    cin >> n;

<<<<<<< HEAD
    int k = 0;
    int bufn = abs(n);
    while(pow(2, k) <= bufn) k++;

    rep(i, k){
        if(bufn & 1<<i) bufn &= ~(1<<i);
        else bufn |= (1<<i);  
    }
    cout << bufn << endl;

    vector<int> binary;
    repr(i, k-1, 0){
        if(bufn & 1<<i) binary.push_back(1);
        else binary.push_back(0);
    }

    for(auto const& e : binary){
        cout << e;
    }
    cout << endl;
=======
    string res = "";
    while(n != 0){
        ll r = n%2;
        n = (n - abs(r)) / (-2);
        res = char('0'+abs(r)) + res;
    }

    if(res.length() == 0) res = '0';

    cout << res << endl;
>>>>>>> 89c6dd77f6639c3a037c460cce91f179a13f0236

    return 0;
}