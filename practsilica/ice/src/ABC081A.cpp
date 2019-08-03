#include <iostream>

using namespace std;


int main(){
    char s[3];
    cin >> s;

    int count = 0;
    for(int i=0; i<3; i++){
        if(s[i] == '1'){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}