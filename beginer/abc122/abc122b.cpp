#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    char s[10];
    cin >> s;
 
    Int max = 0;
    Int len = strlen(s);
 
    Int i = 0;
    Int cnt = 0;
    while(i < len){
        if(s[i]=='A' || s[i]=='T' || s[i]=='C' || s[i]=='G'){
            cnt++;
            max = cnt > max ? cnt : max;
        }else{
            cnt = 0;
        }
        i++;
    }
    cout << max << endl;
    return 0;
}