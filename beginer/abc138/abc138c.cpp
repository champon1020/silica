#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    double n;
    vector<double> v;
    double tmp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    while(v.size() > 1){
        sort(v.begin(), v.end());
        double a, b;
        a = v[0];
        b = v[1];
        v.erase(v.begin(), v.begin()+2);
        v.push_back((a+b)/2);
    }
    printf("%.6lf\n", v[0]);
    return 0;
}