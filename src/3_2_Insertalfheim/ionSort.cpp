/*
    INSERTION SORT <C++>

    This is Insertion Sort Algorithm.
    Calculation order is O(N**2).
    If the datas has been aligned certain degree, this algorithm is effective.
*/

#include <iostream>

using namespace std;

void output(int array[], int n);
void insertionSort(int array[], int n);


void output(int array[], int n){
    for(int l=0; l<n; l++){
        cout << array[l];
    }
    cout << "\n";
}

void insertionSort(int array[], int n){
    for(int j=1; j<n; j++){
        int var = array[j];
        int k = j-1;

        while(k >= 0 && var < array[k]){
            array[k+1] = array[k];
            k--;
        }
        array[k+1] = var;
        output(array, n);
    }
}

int main()
{
    int n;
    int array[100];

    cout << "num: ";
    cin >> n;

    cout << "values (open space between each values)\n";
    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    output(array, n);
    insertionSort(array, n);

    // loop
    while(true){
        ;
    }
}