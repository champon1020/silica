#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, k;
    char s[51];
    cin >> n >> k;
    cin >> s;

    if(s[k-1] == 'A'){
        s[k-1] = 'a';
    }
    if(s[k-1] == 'B'){
        s[k-1] = 'b';
    }
    if(s[k-1] == 'C'){
        s[k-1] = 'c';
    }

    cout << s << endl;

    return 0;
}