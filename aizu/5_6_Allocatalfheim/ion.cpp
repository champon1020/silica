#include <iostream>
#include <cstdio>

#define MAX 100000
typedef long long llong;

using namespace std;

int n, k, w;
llong bag[MAX];


int check(llong P){
    int i = 0;

    for(int j=0; j<k; j++){
        llong sum = 0;
        while(sum + bag[i] <= P){
            sum += bag[i];
            i++;
            if(i == n) return n;
        }
    }

    return i;   
}


int solve(){
    llong left = 0;
    llong right = 100000 * 10000;
    llong mid;
    
    while(right - left > 1){
        mid = (left + right) / 2;
        int v = check(mid);

        if(v >= n){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    return right;
}


int main(){
    // input
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &bag[i]);
    }

    llong ans = solve();

    cout << ans << "\n";
}