#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e10
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<lli>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> bool chmax(T &a, T &b){ if(a<b) { a=b; return 1; }}
template<typename T> bool chmin(T &a, T &b){ if(b<a) { a=b; return 1; }}
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T arrdebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, tmp;
    vector<int> evenind(100001, 0);
    vector<int> oddind(100001, 0);
    cin >> n;
    rep(i, n){
        cin >> tmp;
        if(i%2==0) oddind[tmp]++;
        else evenind[tmp]++;
    }

    int evenmax = 0;
    int oddmax = 0;
    bool flg = false;
    int buf = 0;
    rep(i, 1e5+1){
        if(evenind[i] == 0 && oddind[i] == 0) continue;
        if(evenind[i] > 0 && oddind[i] > 0){
            if(evenind[i] > oddind[i]){
                evenmax = evenind[i];
            }else if(evenind[i] < oddind[i]){
                oddmax = oddind[i];
            }else{
                if(flg){
                    evenmax = max(evenmax, evenind[i]);
                    oddmax = max(oddmax, oddind[i]);
                    continue;
                }
                flg = true;
                buf = i;
            }
            continue;
        }
        evenmax = max(evenmax, evenind[i]);
        oddmax = max(oddmax, oddind[i]);
    }

    if(flg){
        //cout << evenmax << " " << oddmax << endl;
        if(evenmax > oddmax){
            oddmax = oddind[buf];
        }else{
            evenmax = evenind[buf];
        }
    }

    cout << n/2-evenmax + ceil(n, 2)-oddmax << endl;

    return 0;
}