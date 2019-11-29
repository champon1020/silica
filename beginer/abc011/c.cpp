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

    int n, ng1, ng2, ng3;
    cin >> n >> ng1 >> ng2 >> ng3;

    if(n == ng1 || n == ng2 || n == ng3){
        ans2(false);
        return 0;
    }

    ll cnt = 0;
    ll sum = n;
    while(sum > 0){
        if(sum-3 == ng1 || sum-3 == ng2 || sum-3 == ng3){
            if(sum-2 != ng1 && sum-2 != ng2 && sum-2 != ng3){
                if(sum-5 != ng1 && sum-5 != ng2 && sum-5 != ng3){
                    sum -= 5;
                    cnt += 2;
                }else if(sum-4 != ng1 && sum-4 != ng2 && sum-4 != ng3){
                    sum -= 4;
                    cnt += 2;
                }else{
                    ans2(false);
                    return 0;
                }
            }else if(sum-1 != ng1 && sum-1 != ng2 && sum-1 != ng3){
                if(sum-4 != ng1 && sum-4 != ng2 && sum-4 != ng3){
                    sum -= 4;
                    cnt += 2;
                }else{
                    ans2(false);
                    return 0;
                }
            }else{
                ans2(false);
                return 0;
            }
        }else{
            sum -= 3;
            cnt++;
        }
        //cout << sum << endl;
    }

    if(cnt > 100) ans2(false);
    else ans2(true);

    //cout << cnt << endl;

    return 0;
}
