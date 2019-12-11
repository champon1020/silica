#include <iostream>

using namespace std;


int binarySearch(int A[], int n, int key){
    int left = 0;
    int right = n;
    while(left < right){
        int center = (int)((right+left)/2);
        if(A[center] == key){
            return 1;
        }
        if(A[center] > key){
            right = center;
        }
        if(A[center] < key){
            left = center+1;
        }
    }
    return 0;
}


int main(void){
    int n, A[100000];
    int q, key;
    int sum = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for(int i=0; i<q; i++){
        scanf("%d", &key);
        if(binarySearch(A, n, key)){
            sum++;
        }
    }

    printf("%d\n", sum);
}