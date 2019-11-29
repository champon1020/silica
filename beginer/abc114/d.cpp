#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
#define enl << endl
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a[101];

    reps(i, 1, n){
        a[i] = 0;
        int num = i;
        int q = 2;
        while(num > 1){
            if(num%q == 0){
                num /= q;
                a[q]++;
            }else{
                q++;
            }
        }
    }

    ll res = 0;
    reps(i, 1, n){
        if(a[i] >= 74) res++;
    }

    int twentyfour=0, two=0;
    reps(i, 1, n){
        if(a[i] >= 24){
            twentyfour++;
        }
        if(a[i] >= 2){
            two++;
        }
    }
    res += twentyfour * (two-1);

    int fourteen=0, four=0;
    reps(i, 1, n){
        if(a[i] >= 14){
            fourteen++;
        }
        if(a[i] >= 4){
            four++;
        }
    }
    res += fourteen * (four-1);

    four=0; two=0;
    reps(i, 1, n){
        if(a[i] >= 4){
            four++;
        }
        if(a[i] >= 2){
            two++;
        }
    }
    res += four*(four-1)/2 * (two-2);

    cout << res << endl;

    return 0;
}
