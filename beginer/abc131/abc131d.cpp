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
    cin >> n;
    Int a[200001], b[200001];
    vector<Int> c;
    for(Int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        c.push_back(b[i]-a[i]);
    }
    sort(c.begin(), c.end());
    for(Int i=0; i<n; i++){
        if(c[i] <= 0){
            cout << "No" << endl;
            return 0;
        }
        if(c[i] < i){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}