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


struct Node{
    int x, y;
    Node(int x, int y):x(x),y(y){}
};

bool comp(pair<int, Node> p1, pair<int, Node> p2){
    return p1.first < p2.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, d, a;
    cin >> h >> w >> d;
    vector<pair<int, Node>> xy[100000];
    rep(i, h){
        rep(j, w){
            cin >> a;
            xy[a%d].push_back(make_pair(a, Node(j, i)));
        }
    }

    ll cost[d][h*w/d+10];
    rep(i, d){
        sort(all(xy[i]), comp);
        cost[i][0] = 0;
        reps(j, 1, xy[i].size()-1){
            //if(j == 0) cost[i][j+1] = xy[i][j].second.x + xy[i][j].second.y;
            cost[i][j] = cost[i][j-1] 
                + abs(xy[i][j].second.x - xy[i][j-1].second.x) 
                + abs(xy[i][j].second.y - xy[i][j-1].second.y);
        }
    }

    int q;
    int l, r;
    cin >> q;
    rep(i, q){
        cin >> l >> r;
        int rest = l%d;
        int quotientl = l/d;
        int quotientr = r/d;
        if(rest == 0){
            quotientr--;
            quotientl--;
        }
        cout << cost[rest][quotientr] - cost[rest][quotientl] << endl;
    }

    return 0;
}
