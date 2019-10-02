#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int h, w, a, b;
    cin >> h >> w >> a >> b;

    for(Int i=0; i<h; i++){
        for(Int j=0; j<w; j++){
            if(i<b){
                if(j<a){
                    cout << "0";
                }else{
                    cout << "1";
                }
            }else{
                if(j<a){
                    cout << "1";
                }else{
                    cout << "0";
                }
            }
        }
        cout << endl;
    }
    return 0;
}