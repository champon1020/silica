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

    string s;
    cin >> s;

    int slen = s.length();
    bool res = false;
    int marker = 0;
    rep(i, slen){
        if(i >= 1 && s[i] == s[i-1]){
            res = false;
            break;
        }
        if(marker == (1<<5)-1 && s[i] != 'A'){
            res = false;
            break;
        }
        if(marker == 1<<0 && s[i] == 'A'){
            res = false;
            break;
        }
        if(marker == (1<<2)-1 && s[i] == 'A'){
            res = false;
            break;
        }

        if(s[i] == 'K' && marker == 0) marker |= 1<<0;
        else if(s[i] == 'I' && marker & 1<<0) marker |= 1<<1;
        else if(s[i] == 'H' && marker & 1<<1) marker |= 1<<2;
        else if(s[i] == 'B' && marker & 1<<2) marker |= 1<<3;
        else if(s[i] == 'R' && marker & 1<<3){
            marker |= 1<<4;
            res = true;
        }else{
            if(s[i] != 'A') marker = 0;
        }
    }

    ans2(res);

    return 0;
}
