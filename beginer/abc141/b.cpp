#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    bool flg = true;

    for(int i=0; i<s.length(); i++){
        if((i+1)%2 == 1){
            if(s.at(i) == 'R' || s.at(i) == 'U' || s.at(i) == 'D'){
                continue;
            }else{
                flg = false;
                break;
            }
        }
        if((i+1)%2 == 0){
            if(s.at(i) == 'L' || s.at(i) == 'U' || s.at(i) == 'D'){
                continue;
            }else{
                flg = false;
                break;
            }
        }
    }
    if(flg){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}