#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;


int main(){
    int n, k;
    char s[100000];
    cin >> n >> k;
    cin >> s;
    
    int max = 0;
    int sum = 0;
    int l, r;
    for(int i=0; i<k; i++){
        sum = 0;
        for(int j=0; j<n; j++) {
            if(s[j] == 'R'){
                l = j;
                break;
            }
        }
        for(int j=n-1; j>=0; j--) {
            if(s[j] == 'R'){
                r = j;
                break;
            }
        }
        int diff = r-l;
        for(int j=0; j<=diff/2; j++){
            if(l > r){
                break;
            }
            char tmp = s[l] == 'R' ? 'L' : 'R';
            s[l] = s[r] == 'R' ? 'L' : 'R';
            s[r] = tmp;
            l++;
            r--;
        }
        for(int i=1; i<n; i++){
            if(s[i-1] == 'L' && s[i] == 'L') {
                sum++;
            }
        }
        max = max > sum ? max : sum;
    }
    cout << max << endl;
    return 0;
}