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
    map<Int, Int> amap;
    vector<Int> c[1001];

    cin >> n >> m;
    for(Int i=1; i<=m; i++){
        cin >> a >> b;
        amap.insert(make_pair(a, i));
        for(Int j=0; j<b; j++){
            cin >> tmpi;
            c[i].push_back(tmpi);
        }
    }

    Int cnt = 0;
    Int ans = 0;
    int marker[20];
    for(auto const& aa : amap){
        Int money = aa.first;
        Int index = aa.second;
        for(auto cc : c[index]){
            if(marker[cc] == 0){
                //cout << index << " " << cc << " " << money << endl;
                ans += money;
                marker[cc] = 1;
                cnt++;
            }
        }
    }
    if(cnt < n){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}