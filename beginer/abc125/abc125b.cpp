#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, v[100], c[100];
    cin >> n;
    vector<Int> cv;
    for(Int i=0; i<n; i++){
        cin >> v[i];
    }
    for(Int i=0; i<n; i++){
        cin >> c[i];
    }
    for(Int i=0; i<n; i++){
        cv.push_back(v[i]-c[i]);
    }
    
    sort(cv.begin(), cv.end());
    
    Int sum = 0;
    for(Int i=cv.size()-1; i>=0; i--){
        if(cv[i] <= 0){
        break;
        }
        sum += cv[i];
    }
    cout << sum << endl;

    return 0;
}