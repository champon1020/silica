#include <iostream>
#include <cmath>
#define MAX 2000

using namespace std;


long f(long k){
    return (k*(k+1))/2;
}


int main(){
    long n, k;
    long a[MAX];
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long cnt = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                cnt += f(k);
            }
            if(a[i] < a[j]){
                cnt += f(k-1);
            }
            cnt%=(long)(pow(10,9)+7);
        }
    }
    cout << cnt << endl;
    return 0;
}