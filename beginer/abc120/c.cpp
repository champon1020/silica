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

    char marker = s[0];
    Int sum = 1;
    for(Int i=1; i<strlen(s); i++){
        if(s[i] == marker){
            sum++;
        }
    }
    
    if(strlen(s)-sum < sum){
        sum = strlen(s)-sum;
    }
    cout << sum*2 << endl;
    return 0;
}