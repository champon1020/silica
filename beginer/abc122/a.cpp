#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char s;
    cin >> s;

    if(s=='A'){
        cout << 'T' << endl;
    }
    if(s=='T'){
        cout << 'A' << endl;
    }
    if(s=='C'){
        cout << 'G' << endl;
    }
    if(s=='G'){
        cout << 'C' << endl;
    }
    return 0;
}