#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char s[100000];
    Int a[100000];
    cin >> s;
    Int len = strlen(s);
    int rl = 0;
    int l=0, r=1;
    char now = 'R';
    for(Int i=0; i<len; i++){
        a[i] = 0;
    }
    for(Int i=1; i<len; i++){
        if(now != s[i]){
            if(now == 'R'){
                rl = i;
                l = 1;
                now = 'L';
            }else{
                a[rl-1] = l/2;
                a[rl-1] += r%2==0 ? r/2 : r/2+1;
                a[rl] = r/2;
                a[rl] += l%2==0 ? l/2 : l/2+1;
                r = 1;
                l = 0;
                now = 'R';
            }
        }else{
            if(now == 'R'){
                r++;
            }else{
                l++;
            }
        }
    }
    a[rl-1] = l/2;
    a[rl-1] += r%2==0 ? r/2 : r/2+1;
    a[rl] = r/2;
    a[rl] += l%2==0 ? l/2 : l/2+1;
    for(Int i=0; i<len; i++){
        cout << a[i] << endl;
    }
    return 0;
}