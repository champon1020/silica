#include <iostream>

using namespace std;


int main(){
    int n;
    long max;
    cin >> n;

    for(long i=1; i<n; i++){
        max += i;
    }
    cout << max << endl;
    return 0;
}