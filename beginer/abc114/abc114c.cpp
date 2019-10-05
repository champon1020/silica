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
using lli = long long int;
template<typename T> bool chmax(T &a, T &b){ if(a<b) { a=b; return 1; }}
template<typename T> bool chmin(T &a, T &b){ if(b<a) { a=b; return 1; }}
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T arrdebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


lli n, res=0;
 
void rec(lli num){
	if(num > n) return;
	
	lli tmp = num;
	vector<int> marker(10, 0);
	
	while(tmp > 0){
		marker[tmp%10] = 1;
		tmp/=10;
	}
	
	if(marker[3] && marker[5] && marker[7]) res++;
	
	//vdebug(marker);
	//cout << num << " " << res << endl;
	
	rec(num*10 + 3);
	rec(num*10 + 5);
	rec(num*10 + 7);
}
	
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    rec(0);
    
    cout << res << endl;
    
  	return 0;
}