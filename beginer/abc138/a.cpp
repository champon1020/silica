#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    string s;
    cin >> a >> s;
    if(a < 3200){
        cout << "red" << endl;
    }else{
        cout << s << endl;
    }

    return 0;
}