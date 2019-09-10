#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p[100000];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    int max = 0;
    int max2 = 0;
    int sum = 0;
    for(int i=0; i<n-1; i++){
        int max = 0;
        int max2 = 0;
        for(int j=i+1; j<n; j++){
            if(i+1==j) {
                sum += p[i] > p[j] ? p[j] : p[i];
                max = p[i] < p[j] ? p[j] : p[i];
                max2 = sum;
                continue;
            }
            if(p[j] > max) {
                sum += max;
                max2 = max;
                max = p[j];
            }else if(p[j] < max && p[j] > max2) {
                sum += p[j];
                max2 = p[j];
            }else {
                sum += max2;
            }
        }
    }
    cout << sum << endl;
    return 0;
}