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

    int n, l;
    string sin;
    char kuji[50][50];
    int leader;
    cin >> n >> l;
    reps(i, 0, l+1){
        getline(cin, sin);
        if(i==0) continue;
        //cout << sin.length() sp sin << endl;
        reps(j, 1, n*2-1){
            kuji[i][j] = sin[j-1];
            if(kuji[i][j] == 'o') leader = (j+1)/2;
        }
    }

    //cout << kuji[1][16] sp kuji[2][16] << endl;

    int x = leader * 2 - 1;
    int y = l;
    int visit[50][50];
    Fill(visit, 0);
    int res = 0;
    while(true){
        //cout << x sp y << endl;
        visit[y][x] = 1;
        if(x - 1 >= 1 && kuji[y][x-1] == '-'){
            if(!visit[y][x-2]){
                x -= 2;
                continue;
            }
        }

        //cout << kuji[y][x+1] sp kuji[y][x+3] << endl;
        if(x + 1 <= 2*n - 1 && kuji[y][x+1] == '-'){
            if(!visit[y][x+2]){
                x += 2;
                continue;
            }
        }
        if(y == 1){
            res = (x + 1) / 2;
            break;
        }
        y--;
    }

    cout << res << endl;

    // reps(i, 1, l+1){
    //     reps(j, 1, 2*n-1){
    //         cout << kuji[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}
