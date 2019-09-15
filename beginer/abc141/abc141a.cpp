#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if(s == "Sunny") {
        cout << "Cloudy" << endl;
    }
    if(s == "Cloudy") {
        cout << "Rainy" << endl;
    }
    if(s == "Rainy"){
        cout << "Sunny" << endl;
    }
    return 0;
}