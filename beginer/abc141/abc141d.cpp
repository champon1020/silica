#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Int n, m;
    cin >> n >> m;
    vector<Int> a;
    Int tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    Int p = 0;
    Int sum = 0;
    for(int i=n-1; i>=0; i--){
        cout << m << endl;
        if(m > 1){
            for(int j=0; j<=m; j++){
                if(floor(a[i] / pow(2, j)) <= 1){
                    p = j-1;
                    break;
                }
            }
        }else{
            p = (m == 1) ? 1 : 0;
        }
        m -= p;
    }
    cout << sum << endl;
    return 0;
}