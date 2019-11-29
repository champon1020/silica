#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


Int n, m;
Int sw[10];
Int k[10];
Int p[10], s[10][10];
Int cnt = 0;

void init(){
    for(Int i=0; i<n; i++){
        sw[i] = 0;
    }
}

void printdbg(){
    for(Int i=0; i<n; i++){
        cout << sw[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    init();
    for(Int i=0; i<m; i++){
        cin >> k[i];
        for(Int j=0; j<k[i]; j++){
            cin >> s[i][j];
        }
    }
    for(Int i=0; i<m; i++){
        cin >> p[i];
    }

    for(int bit=0; bit<(1<<n); bit++){
        init();
        bool flg = true;
        for(int i=0; i<n; i++){
           if(bit & (1<<i)){
               sw[i] = 1;
           }
        }
        
        for(Int i=0; i<m; i++){
            Int sum = 0;
            for(Int j=0; j<k[i]; j++){
                if(sw[s[i][j]-1] == 1){
                    sum++;
                }
            }
            if(sum%2 != p[i]){
                flg = false;
                break;
            }
        }
        if(flg){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}