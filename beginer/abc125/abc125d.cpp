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
    vector<Int> a;
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> tmpi;
        a.push_back(tmpi);
    }
    sort(a.begin(), a.end());
    Int cnt=0;
    Int sum=0;
    for(Int i=0; i<n; i++){
        if(a[i] > 0){
            sum += a[i];
            continue;
        }
        sum += abs(a[i]);
        a[i] = abs(a[i]);
        cnt++;
    }
    sort(a.begin(), a.end());
    if(cnt%2==1){
        sum -= 2*a[0];
    }
    cout << sum << endl;
    return 0;
}