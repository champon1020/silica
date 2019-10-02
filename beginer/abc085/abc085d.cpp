#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<Int> a, b;
    Int n, h, aa, bb;
    cin >> n >> h;
    for(Int i=0; i<n; i++){
        cin >> aa >> bb;
        a.push_back(aa);
        b.push_back(bb);
    }
    sort(a.begin(), a.end(), greater<Int>());
    sort(b.begin(), b.end(), greater<Int>());

    Int marker = b.size()-1;
    for(Int i=0; i<n; i++){
        if(b[i] < a[0]){
            marker = i-1;
            break;
        }
    }

    Int cnt = 0;
    Int sum = 0;
    for(Int i=0; i<n; i++){
        if(sum >= h) break;
        if(i > marker) break;
        sum += b[i];
        cnt++;
    }
    if(sum < h){
        cnt += (h-sum + a[0]-1)/a[0];
    }
    cout << cnt << endl;

    return 0;
}