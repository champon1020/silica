#include <iostream>
#define MAX 44

using namespace std;

int f[MAX];

int fibonacci(int n){
    if(n==0 || n==1){
        f[n] = 1;
        return f[n];
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n] = fibonacci(n-2) + fibonacci(n-1);
    return f[n];
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<MAX; i++){
        f[i] = -1;
    }
    int out = fibonacci(n);
    cout << out << endl;
    return 0;
}