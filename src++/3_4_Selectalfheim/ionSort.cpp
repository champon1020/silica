/*
    SELECTION SORT <C++>

    This is selection sort algorithm.
    Calculation order is O(N**2).
    This is not stable.
*/

#include <iostream>

using namespace std;

void selectionSort(int array[], int n);

void selectionSort(int array[], int n){
    int count = 0;
    
    for(int i=0; i<n; i++){
        int minind = i;
        for(int j=i; j<n; j++){
            if(array[j] < array[minind]){
                minind = j;
            }
        }
        int buf = array[i];
        array[i] = array[minind];
        array[minind] = buf;
        if(minind != i){
            count++;
        }
    }

    // output
    cout << "-------------------------------" << endl;
    for(int k=0; k<n; k++){
        cout << array[k] << " ";
    }
    cout << endl << "Num of exchanges: " << count << endl;
}

int main(){
    int n;
    int array[100];

    // input
    cout << "num: ";
    cin >> n;
    cout << "array numbers:" << endl;
    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    selectionSort(array, n);

    // loop
    while(true){
        ;
    }
    return 0;
}