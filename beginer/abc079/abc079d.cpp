#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int h, w;
int c[10][10];
int a[500][500];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> c[i][j];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }

    
    for(int k=0; k<10; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }

    Int ans = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            ans += c[a[i][j]][1];
        }
    }
    cout << ans << endl;

    return 0;
}