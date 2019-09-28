#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<Int> v;
    vector<Int> v2;
    for(Int i=0; i<5; i++){
        cin >> tmpi;
        v.push_back(tmpi);
    }

    Int min = 1000;
    Int minind = 1000;
    for(Int i=0; i<v.size(); i++){
        tmpi = v[i]/10;
        Int tmpi2 = v[i] - tmpi*10;
        if(tmpi2 == 0){
            v2.push_back(v[i]);
            continue;
        }
        if(tmpi2 < min){
            min = tmpi2;
            minind = i;
        }
        v2.push_back(tmpi*10+10);
    }

    v2[minind] = v[minind];

    Int sum = 0;
    for(Int i=0; i<v2.size(); i++){
        sum += v2[i];
    }
    cout << sum << endl;

    return 0;
}