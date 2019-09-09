#include <iostream>

using namespace std;


int main(){
    int k, s;
    cin >> k >> s;

    int count = 0;
    for(int p=0; p<=k; p++){
        for(int q=0; q<=k; q++){
            if(s-p-q <= k && s-p-q >= 0){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}