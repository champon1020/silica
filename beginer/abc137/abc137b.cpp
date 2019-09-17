#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int k, x;
    cin >> k >> x;
    vector<Int> v;

    Int cur = x-(k-1);
    while(cur <= x+(k-1)){
        if(cur < -1000000){
            cur++;
            continue;
        }
        if(cur > 1000000){
            break;
        }
        v.push_back(cur);
        cur++;
    }
    for(Int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}