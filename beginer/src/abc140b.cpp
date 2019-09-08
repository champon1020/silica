#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;


int main(){
    int n, a[20], b[20], c[20];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0; i<n-1; i++){
        cin >> c[i];
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += b[a[i]-1]; // b
        if(i == 0){
            continue;
        }
        if(a[i-1] + 1 == a[i]) {
            sum += c[a[i-1]-1]; // c
        }
    }
    cout << sum << endl;
    return 0;
}