#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    double sum = 0.0;
    double a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        sum += 1/a;
    }
    printf("%.7lf", 1/sum);
    return 0;
}