#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, tmp;
    vector<Int> a;
    priority_queue<Int> aa;
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> tmp;
        a.push_back(tmp);
        aa.push(tmp);
    }
    for(Int i=0; i<n; i++){
        if(aa.top() == a[i]){
            aa.pop();
            cout << aa.top() << endl;
            aa.push(a[i]);
        }else{
            cout << aa.top() << endl;
        }
    }
    return 0;
}