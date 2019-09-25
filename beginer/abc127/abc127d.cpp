#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, m;
    vector<Int> a;
    multimap<Int, Int, greater<Int>> bc;
    cin >> n >> m;
    for(Int i=0; i<n; i++){
        cin >> tmpi;
        a.push_back(tmpi);
    }

    Int tmpi2;
    for(Int i=0; i<m; i++){
        cin >> tmpi >> tmpi2;
        bc.insert(make_pair(tmpi2, tmpi));
    }
    sort(a.begin(), a.end());
    Int it = 0;
    Int sum = 0;
    Int cnt = 0;
    for(const auto& u : bc){
        Int num = u.first;
        Int len = u.second;
        bool flg = false;
        Int maxlen = it+len < n ? it+len : n;
        for(Int i=maxlen-1; i>=it; i--){
            cnt++;
            if(a[i] < num){
                sum += num*(i-it+1);
                it = i+1;
                if(cnt != bc.size()){
                    flg = true;
                }
                break;
            }
        }
        if(!flg){
            for(Int i=it; i<n; i++){
                sum += a[i];
            }
            break;
        }
    }

    cout << sum << endl;
    return 0;
}