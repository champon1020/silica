#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b){
    return a <= b ? a : b;
}

int main(){
    int n, a[150000], b[150000];
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> b[i];
    }
    a[0] = b[0];
    for(int i=1; i<n-1; i++){
        a[i] = min(b[i], b[i-1]);
    }
    a[n-1] = b[n-2];
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}