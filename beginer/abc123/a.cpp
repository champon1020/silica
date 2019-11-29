#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int dist[5], k;
    for(Int i=0; i<5; i++){
        cin >> dist[i];
    }
    cin >> k;

    Int cnt = 0;
    for(Int i=0; i<5; i++){
        for(Int j=i+1; j<5; j++){
            if(dist[j]-dist[i] <= k){
                cnt++;
            }
        }
    }
    if(cnt == 10){
        cout << "Yay!" << endl;
    }else{
        cout << ":(" << endl;
    }

    return 0;
}