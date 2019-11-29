#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, m, tmp;
    priority_queue<int> q;
    cin >> n >> m;
    for(Int i=0; i<n; i++){
        cin >> tmp;
        q.push(tmp);
    }
    for(Int i=0; i<m; i++){
        Int buf = q.top();
        q.pop();
        q.push(buf/2);
    }
    Int sum = 0;
    for(Int i=0; i<n; i++){
        sum += q.top();
        q.pop();
    }
    cout << sum << endl;
    return 0;
}