#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int k, x, y, z;
    vector<Int> a, b, c;
    cin >> x >> y >> z >> k;
    for(Int i=0; i<x; i++){
        cin >> tmpi;
        a.push_back(tmpi);
    }
    for(Int i=0; i<y; i++){
        cin >> tmpi;
        b.push_back(tmpi);
    }
    for(Int i=0; i<z; i++){
        cin >> tmpi;
        c.push_back(tmpi);
    }

    sort(a.begin(), a.end(), greater<Int>());
    sort(b.begin(), b.end(), greater<Int>());
    sort(c.begin(), c.end(), greater<Int>());
    
    vector<Int> ab;
    for(Int i=0; i<x; i++){
        for(Int j=0; j<y; j++){
            ab.push_back(a[i]+b[j]);
        }
    }
    sort(ab.begin(), ab.end(), greater<Int>());

    vector<Int> abc;
    int num = k > x*y ? x*y : k;
    for(Int i=0; i<num; i++){
        for(Int j=0; j<z; j++){
            abc.push_back(ab[i]+c[j]);
        }
    }

    sort(abc.begin(), abc.end(), greater<Int>());
    for(Int i=0; i<k; i++){
        cout << abc[i] << endl;
    }
    return 0;
}