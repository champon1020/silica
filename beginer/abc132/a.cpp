#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char s[4];
    char s1, s2='0';
    Int c1=0, c2=0;
    cin >> s;

    s1 = s[0];
    c1++;
    for(Int i=1; i<4; i++){
        if(s[i] == s1){
            c1++;
            continue;
        }
        if(s[i] != s1 && s2 == '0'){
            s2 = s[i];
            c2++;
            continue;
        }
        if(s[i] == s2){
            c2++;
            continue;
        }
        if(s[i] != s1 && s[i] != s2){
            cout << "No" << endl;
            return 0;
        }
    }
    if(c1 == 2 && c2 == 2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}