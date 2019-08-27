#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


int main(){
    string s;
    cin >> s;

    int sum = 0;
    int arr[3];
    for(int bit=0; bit<(1<<3); bit++){
        sum = s.at(0)-'0';
        for(int i=0; i<3; i++){
            if(bit & (1<<i)){
                arr[i] = 1;
                sum -= s.at(i+1)-'0';
            }else{
                arr[i] = 0;
                sum += s.at(i+1)-'0';
            }
        }
        if(sum==7){
            break;
        }
    }

    cout << s.at(0);
    for(int i=0; i<3; i++){
        cout << ((arr[i]==1)? '-' : '+') << s.at(i+1);
    }
    cout << "=7" << endl;
    return 0;
}