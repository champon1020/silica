#include <bits/stdc++.h>
using Int = long long int;
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Int n, k;
    char s[100000];
    cin >> n >> k;
    cin >> s;
    
    Int cnt = 0;
    for(Int i=1; i<n; i++){
        if(s[i-1] == s[i]) cnt++;
    }
    cout << min(n-1, cnt + 2*k) << endl;
    return 0;
}