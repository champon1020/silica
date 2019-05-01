#include <iostream>
#include <vector>

using namespace std;

void insertionSort(int array[], int n, int g);
void shellSort(int array[], int n);
int COUNT = 0;
vector<int> g;


void insertionSort(int array[], int n, int g){
    for(int i=g; i<n; i++){
        int value = array[i];
        int j = i - g;
        while(j >= 0 && array[j] > value){
            array[j+g] = array[j];
            j = j - g;
            COUNT++;
        }
        array[j+g] = value;
    }
}


void shellSort(int array[], int n){
    for(int h=1; ; ){
        if(h > n) break;
        g.push_back(h);
        h = 3*h + 1;
    }

    for(int i=g.size()-1; i>=0; i--){
        insertionSort(array, n, g[i]);
    }
}


int main(){
    int n;
    int array[10000];

    cout << "num: ";
    cin >> n;
    cout << "array:" << endl;
    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    shellSort(array, n);

    for(int i=0; i<n; i++) printf("%d ", array[i]);
    printf("\ncnt: %d\n", COUNT);
    return 0;
}