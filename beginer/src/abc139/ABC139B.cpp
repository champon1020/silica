#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int i = 1;
    int cnt = 0;
    while(true){
        if(i >= b){
            break;
        }
        i += a-1;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}