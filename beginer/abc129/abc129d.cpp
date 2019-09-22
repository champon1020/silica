#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int h, w;
    cin >> h >> w;
    char s[2001][2001];
    Int l[2001][2001];
    Int r[2001][2001];
    Int u[2001][2001];
    Int d[2001][2001];
    for(Int i=0; i<h; i++){
        cin >> s[i];
    }

    // left
    for(Int i=0; i<h; i++){
        for(Int j=0; j<w; j++){
            if(j==0){
                l[i][j] = 0;
                continue;
            }
            if(s[i][j]=='#'){
                l[i][j] = 0;
                continue;
            }
            if(s[i][j-1]=='#'){
                l[i][j] = 0;
            }else{
                l[i][j] = l[i][j-1] + 1;
            }
        }
    }

    // right
    for(Int i=0; i<h; i++){
        for(Int j=w-1; j>=0; j--){
            if(j==w-1){
                r[i][j] = 0;
                continue;
            }
            if(s[i][j]=='#'){
                r[i][j] = 0;
                continue;
            }
            if(s[i][j+1]=='#'){
                r[i][j] = 0;
            }else{
                r[i][j] = r[i][j+1] + 1;
            }
        }
    }

    // up
    for(Int i=0; i<h; i++){
        for(Int j=0; j<w; j++){
            if(i==0){
                u[i][j] = 0;
                continue;
            }
            if(s[i][j]=='#'){
                u[i][j] = 0;
                continue;
            }
            if(s[i-1][j]=='#'){
                u[i][j]=0;
            }else{
                u[i][j] = u[i-1][j] + 1;
            }
        }
    }

    // down
    for(Int i=h-1; i>=0; i--){
        for(Int j=0; j<w; j++){
            if(i==h-1){
                d[i][j] = 0;
                continue;
            }
            if(s[i][j]=='#'){
                d[i][j] = 0;
                continue;
            }
            if(s[i+1][j]=='#'){
                d[i][j] = 0;
            }else{
                d[i][j] = d[i+1][j] + 1;
            }
        }
    }

    Int max = 0;
    for(Int i=0; i<h; i++){
        for(Int j=0; j<w; j++){
            tmpi = l[i][j] + r[i][j] + u[i][j] + d[i][j] + 1;
            max = tmpi > max ? tmpi : max;
        }
    }
    cout << max << endl;
    return 0;
}