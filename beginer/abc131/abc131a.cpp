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
    cin >> s;

    if(s[0]==s[1] || s[1]==s[2] || s[2]==s[3]){
        cout << "Bad" << endl;
    }else{
        cout << "Good" << endl;
    }

    return 0;
}