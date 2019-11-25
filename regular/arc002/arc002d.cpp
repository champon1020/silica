#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define ceil(a, b) (a+b-1)/b
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

    string day;
    cin >> day;

    vector<string> el;
    string buf = "";
    rep(i, day.length()){
        if(day[i] == '/'){
            el.push_back(buf);
            buf = "";
        }else{
            buf += day[i];
        }
    }
    el.push_back(buf);

    int y = stoi(el[0]);
    int m = stoi(el[1]);
    int d = stoi(el[2]);

    //cout << y sp m sp d << endl;

    while(y%m != 0 || y / m % d != 0){
        if(m == 4 || m == 6 || m == 9 || m == 11){
            if(d == 30){
                d = 1;
                m++;
            }else d++;
        }
        else if(m == 12){
            if(d == 31){
                y++;
                m = 1;
                d = 1;
            }else d++;
        }
        else if(m == 2){
            bool uru = false;
            if(y % 400 == 0) uru = true;
            else if(y % 100 == 0) uru = false;
            else if(y % 4 == 0) uru = true;

            if(uru){
                if(d == 29){
                    d = 1;
                    m++;
                }else d++;
            }else{
                if(d == 28){
                    d = 1;
                    m++;
                }else d++;
            }
        }
        else{
            if(d == 31){
                m++;
                d = 1;
            }else d++;
        }
    }

    string mm = to_string(m), dd = to_string(d);
    if(m/10 == 0) mm = '0' + mm; 
    if(d/10 == 0) dd = '0' + dd;

    cout << y << "/" << mm << "/" << dd << endl;

    return 0;
}
