#include <iostream>

using namespace std;



int linearSearch(int A[], int n, int key){
    int i = 0;
    A[n] = key;
    while(A[i]!=key){
        i++;
    }
    return i != n;
}


int main(void){
    int n, A[100000+1], q;
    int key, sum=0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for(int i=0; i<q; i++){
        scanf("%d", &key);
        if(linearSearch(A, n, key)){
            sum++;
        }
    }

    printf("%d\n", sum);
}