#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char s[100001];
    cin >> s;
    Int len = strlen(s);
    char marker = '0';
    Int min = 1000000000;
    
    for(Int i=0; i<2; i++){
        Int sum = 0;
        if(i==1){
            marker = '1';
        }
        for(Int j=0; j<len; j++){
            if(j%2==0){
                sum += s[j]==marker ? 0 : 1;
            }else{
                sum += s[j]!=marker ? 0 : 1;
            }
        }
        min = sum < min ? sum : min;
    }
    cout << min << endl;
    return 0;
}