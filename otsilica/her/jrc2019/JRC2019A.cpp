#include <iostream>

using namespace std;


int main(){
    int m, d, cnt=0;
    cin >> m >> d;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=d; j++){
            int d1 = j%10;
            int d2 = j/10;
            if(d1 >= 2 && d2 >= 2 && d1*d2==i){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}