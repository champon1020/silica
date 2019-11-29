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
template<typename T> void vdeb(T v){
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
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    map<char, int> cnt;
    int slen = s.length();
    rep(i, slen){
        cnt[s[i]]++;
    }

    bool good = false;
    if(cnt.size() < 26){
        rep(i, 26){
            char buf = char(i+'a');
            if(cnt[buf] > 0) continue;
            else{
                good = true;
                s += buf;
                break;
            }
        }
    }else{
        set<char> seen;
        seen.insert(s[slen-1]);
        repr(i, slen-2, 0){
            int num = s[i]-'a';
            reps(j, num+1, 26){
                char tmp = char(j + 'a');
                if(seen.find(tmp) != seen.end()){
                    s[i] = tmp;
                    s = s.substr(0, i+1);
                    good = true;
                    break;
                }
            }
            if(good) break;
            seen.insert(s[i]);
        }
    }

    if(!good) cout << -1 << endl;
    else cout << s << endl;

    return 0;
}
