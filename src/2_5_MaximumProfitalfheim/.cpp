/*
    This algorithm can get the max profit of trading.
    Very easy training.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int R[200000];

    cout << "num: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "num[" << i << "]: " << endl;
        cin >> R[i];
    }

    int maxvar = -100000;
    int minvar = R[0];

    for(int j=1; j<n; j++){
        maxvar = max(maxvar, R[j]-minvar);
        minvar = min(minvar, R[j]);
    }

    cout << "max profit: " << maxvar;


    // loop
    while(true){
        ;
    }
}