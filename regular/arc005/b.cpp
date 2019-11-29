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


class BPCAS {
public:
	void solve(std::istream& in, std::ostream& out) {
	    string w, tmp;
	    int c[10][10];
	    int x, y;
	    in >> x >> y >> w;
	    reps(i, 1, 9){
            in >> tmp;
	        reps(j, 1, 9){
	            c[j][i] = tmp[j-1] - '0';
	        }
	    }

//	    reps(i, 1, 9){
//	        reps(j, 1, 9){
//	            out << c[j][i];
//	        }
//	        out << endl;
//	    }
//	    out << endl;

	    int dx=0, dy=0;
	    rep(i, w.length()) {
            if (w[i] == 'R') dx = 1;
            if (w[i] == 'L') dx = -1;
            if (w[i] == 'U') dy = -1;
            if (w[i] == 'D') dy = 1;
        }

        int cnt = 0;
	    string res = "";
	    while(cnt < 4){
	        res += to_string(c[x][y]);
            if(x + dx < 1 || x + dx > 9) dx *= -1;
            if(y + dy < 1 || y + dy > 9) dy *= -1;
            x += dx;
            y += dy;
            cnt++;
	    }

	    out << res << endl;
	}
};
