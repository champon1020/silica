#include <iostream>
#define INF 1<<10;

using namespace std;

int main(){
    int n, cnt=0, max=0;
    long h, buf=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> h;
        if(h <= buf){
            cnt++;
        }else{
            max = (cnt > max) ? cnt : max;
            cnt = 0;
        }
        buf = h;
    }
    max = (cnt > max) ? cnt : max;
    cout << max << endl;
    return 0;
}