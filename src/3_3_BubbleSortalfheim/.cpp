/*
    BUBBLE SORT <C++>

    This is bubble sort algorithm.
    Calculation order is O(N**2).
    Num of exchanges expresses array disorder.
    This is Stable.
*/

#include <iostream>

using namespace std;

void bubbleSort(int* array, int n);

void bubbleSort(int* array, int n){
    int count = 0;
    int flag = 1;
    int buf;

    while(flag){
        flag = 0;
        for(int j=0; j<n-1; j++){
            if(array[j] > array[j+1]){
                buf = array[j];
                array[j] = array[j+1];
                array[j+1] = buf;
                count ++;
                flag = 1;
            }
        }
    }

    for(int k=0; k<n; k++) cout << array[k] << " ";
    cout << endl << "Num of exchanges:" << count << endl;
}

int main(){
    int n;
    int array[100];

    cout << "num: ";
    cin >> n;

    cout << "numbers of array:" << endl;
    for(int i=0; i<n; i++) cin >> array[i];

    cout << "--------------------------------" << endl;
    bubbleSort(array, n);

    // loop
    while(true){
        ;
    }
    return 0;
}