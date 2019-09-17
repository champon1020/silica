#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, m, a, b;
    vector<pair<Int, Int>> v;
    priority_queue<Int> pq;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(a > m){
            continue;
        }
        v.push_back(make_pair(a, b));
    }
    Int sum = 0;
    for(Int i=1; i<=m; i++){
        
    }
    cout << sum << endl;
    return 0;
}