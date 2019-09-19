#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n;
    vector<Int> d;
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> tmpi;
        d.push_back(tmpi);
    }

    sort(d.begin(), d.end());
    Int len = d.size();
    Int cl = d[len/2-1];
    Int cr = d[len/2];

    cout << cr-cl << endl;

    return 0;
}