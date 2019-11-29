#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    bool flg[2];
    flg[0] = false;
    flg[1] = false;
    cin >> s;

    tmpi = stoi(s);
    int front = tmpi/100;
    int end = tmpi-front*100;

    if(front > 0 && front <= 12){
        flg[0] = true;
    }
    if(end > 0 && end <= 12){
        flg[1] = true;
    }

    if(flg[0] && flg[1]){
        cout << "AMBIGUOUS" << endl;
    }else if(flg[0]){
        cout << "MMYY" << endl;
    }else if(flg[1]){
        cout << "YYMM" << endl;
    }else{
        cout << "NA" << endl;
    }

    return 0;
}