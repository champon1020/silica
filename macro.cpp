#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define ceill(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
void ans(bool b){ cout << (b ? "Yes" : "No") << endl; }
void ans2(bool b){ cout << (b ? "YES" : "NO") << endl; }
template<typename T> inline bool chmax(T &a, T b){ if(a<b) a=b; return a<b; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a) a=b; return b<a; }
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill((T*)array, (T*)(array+N), val);
}
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
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};


int test(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << "#rep debug" << endl << "  ";
    rep(i, 10){
        cout << i << " ";
    }
    cout << endl;

    cout << "#repr debug" << endl << "  ";
    repr(i, 9, 0){
        cout << i << " ";
    }
    cout << endl;

    cout << "#reps debug" << endl << "  ";
    reps(i, 0, 9){
        cout << i << " ";
    }
    cout << endl;

    cout << "#inf" << endl;
    cout << "  " << inf << endl;

    cout << "#ceil debug" << endl;
    cout << "  equation => 33 / 7" << endl;
    cout << "  res: " << ceill(33, 7) << endl;
    cout << "  ans: 5" << endl;

    cout << "#chmax debug" << endl;
    int a=3, b=5;
    cout << "  before: a=" << a << " b=" << b << endl;
    chmax(a, b);
    cout << "  after:  a=" << a << " b=" << b << endl;

    cout << "#chmax debug" << endl;
    int c=6, d=4;
    cout << "  before: c=" << c << " d=" << d << endl;
    chmin(c, d);
    cout << "  after:  c=" << c << " d=" << d << endl;

    vector<int> v;
    set<int> s;
    int arr[10];
    map<int, int> mp;
    vector<pair<int, int>> vp;
    rep(i, 10){
        v.push_back(i);
        s.insert(i);
        arr[i] = i;
        mp.insert(make_pair(i, i*i));
        vp.push_back(make_pair(i, i*i));
    }

    vdeb(v);
    vdeb(s);
    adeb(arr, 9);
    mdeb(mp);
    mdeb(vp);

    int arr2[10];
    Fill(arr2, 1);
    cout << "#Fill debug" << endl << "  ";
    rep(i, 10){
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "#ans debug" << endl;
    cout << "  true:  "; ans(true);
    cout << "  false: "; ans(false);

    cout << "#ans2 debug" << endl;
    cout << "  true:  "; ans2(true);
    cout << "  false: "; ans2(false);


    cout << endl << endl << "Complete!" << endl;

    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    test();
    return 0;
}