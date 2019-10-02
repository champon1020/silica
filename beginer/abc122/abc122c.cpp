#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    char s[100001];
    cin >> n >> q;
    cin >> s;

    bool flg = false;
    int marker[100001];

    for(int i=0; i<n; i++){
        if(s[i]=='A'){
            flg=true;
            continue;
        }
        if(s[i]=='C' && flg){
            marker[i] = 1;
            flg=false;
            continue;
        }
        flg = false;
        marker[i] = 0;
    }
    int t[100001];
    t[0] = marker[0];
    for(int i=1; i<n; i++){
        t[i] = t[i-1] + marker[i];
    }
    int l, r;
    for(Int i=0; i<q; i++){
        cin >> l >> r;
        cout << t[r-1]-t[l-1] << endl;
    }
    return 0;
}