#include <iostream>
#include <cstdio>

using namespace std;


void merge(int a[], int left, int mid, int right){
    int i = left;
    int j = mid;
    int k = 0;
    int *tmp = new int[right-left];
    while(i < mid && j < right){
        if(a[i] > a[j]){
            tmp[k++] = a[i++];
        }else if(a[i] <= a[j]){
            tmp[k++] = a[j++];
        }
    }
    while(i < mid){
        tmp[k++] = a[i++];
    }
    while(j < right){
        tmp[k++] = a[j++];
    }
    for(int l=0; l<right-left; l++){
        a[left+l] = tmp[l];
    }
}


void mergeSort(int a[], int left, int right){
    if(right-left <= 1){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
}


int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n);
    int alice = 0;
    int bob = 0;
    for(int i=0; i<n; i++){
        if(i%2==0){
            alice += a[i];
        }else{
            bob += a[i];
        }
    }
    cout << alice-bob << endl;
    return 0;
}