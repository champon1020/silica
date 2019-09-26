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
    Int p=a[n-1], q=a[n-2];
    Int r=-1, s=-1;
    Int g=0;
    Int gbuf = 0;
    tmpi = -1;
    for(Int i=n-2; i>=0; i--){
        if(i!=n-2){
            p = a[i];
            q = g;
        }
        while(true){
            s = p/q;
            r = p%q;
            if(r==0){
                gbuf = g;
                g = q;
                break;
            }else{
                p = q;
                q = r;
            }
        }
        if(g == 1){
            if(tmpi!=-1){
                cout << "1" << endl;
                return 0;
            }else{
                tmpi = i;
            }
        }
    }

    cout << gbuf << endl;

    return 0;
}