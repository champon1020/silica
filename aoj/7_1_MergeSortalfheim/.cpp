#include <iostream>
#define MAX 500000
#define INF 200000000

using namespace std;

int L[MAX/2 + 2];
int R[MAX/2 + 2];


void merge(int S[], int left, int mid, int right){
    int n1 = mid-left;
    int n2 = right-mid;
    for(int i=0; i<n1; i++) L[i] = S[left + i];
    for(int i=0; i<n2; i++) R[i] = S[mid + i];

    L[n1] = INF;
    R[n2] = INF;

    int i=0, j=0;
    for(int k=left; k<right; k++){
        if(L[i] <= R[j]){
            S[k] = L[i++];
        }else{
            S[k] = R[j++];
        }
    }
}


void mergeSort(int S[], int n, int left, int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(S, n, left, mid);
        mergeSort(S, n, mid, right);
        merge(S, left, mid, right);
    }
}


int main(){
    int n;
    int S[MAX];

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &S[i]);
    }

    mergeSort(S, n, 0, n);

    for(int i=0; i<n; i++){
        cout << S[i] << " ";
    }
    cout << "\n";

    return 0;
}
