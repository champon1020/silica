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

    int n;
    vector<pair<int, int>> ta;
    int t, a;
    cin >> n;
    rep(i, n){
        cin >> t >> a;
        ta.push_back(make_pair(t, a));
    }

    ll taka = 0, aoki = 0;
    for(auto const& e : ta){
        int t = e.first;
        int a = e.second;
        if(t == a){
            if(taka < aoki){
                taka = aoki;
            }else if(taka > aoki){
                aoki = taka;
            }
            if(taka==0 && aoki==0){
                taka = aoki = 1;
            }
        }else{
            if(taka != 0 && aoki != 0){
                ll taka1 = taka;
                ll aoki1;
                while(taka1 % t != 0){
                    taka1++;
                }
                aoki1 = taka1 / t * a;

                ll taka2;
                ll aoki2 = aoki;
                while(aoki2 % a != 0){
                    aoki2++;
                }
                taka2 = aoki2 / a * t;

                if(taka1 >= taka && aoki1 >= aoki && taka2 >= taka && aoki2 >= aoki){
                    if(taka1+aoki1 < taka2+aoki2){
                        taka = taka1;
                        aoki = aoki1;
                    }else{
                        taka = taka2;
                        aoki = aoki2;
                    }
                }else{
                    if(taka1 >= taka && aoki1 >= aoki){
                        taka = taka1;
                        aoki = aoki1;
                    }else if(taka2 >= taka && aoki2 >= aoki){
                        taka = taka2;
                        aoki = aoki2;
                    }
                }
            }else{
                taka = t;
                aoki = a;
            }
        }
        //cout << taka sp aoki << endl;
    }

    cout << taka+aoki << endl;

    return 0;
}
