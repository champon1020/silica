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
    Int p[20];
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> p[i];
    }

    Int cnt = 0;
    for(Int i=1; i<n-1; i++){
        vector<Int> buf;
        buf.push_back(p[i-1]);
        buf.push_back(p[i]);
        buf.push_back(p[i+1]);
        sort(buf.begin(), buf.end());
        if(buf[1] == p[i]){
            cnt++;
        }    
    }
    cout << cnt << endl;

    return 0;
}