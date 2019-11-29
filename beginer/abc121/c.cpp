#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, m, a, b;
    multimap<Int, Int> mp;

    cin >> n >> m;
    for(Int i=0; i<n; i++){
        cin >> a >> b;
        mp.insert(make_pair(a, b));
    }

    typename map<Int, Int>::iterator it = begin(mp);

    Int cnt = 0;
    Int ans = 0;
    while(cnt < m){
        pair<Int, Int> p = *it;
        Int money = p.first;
        Int limit = p.second;
        for(Int i=0; i<limit; i++){
            if(cnt >= m){
                break;
            }
            ans += money; 
            cnt++;
        }
        it++;
    }
    cout << ans << endl;

    return 0;
}