#include <iostream>
#include <cstdio>
#define MAX 100000

using namespace std;


void swap(int &x, int &y){
    int buf = x;
    x = y;
    y = buf;
}

int partition(int S[], int p, int r){
    int x = S[r];
    int i = p-1;
    for(int j=p; j<r; j++){
        if(S[j] <= x){
            i++;
            swap(S[i], S[j]);
        }
    }
    swap(S[i+1], S[r]);

    return i+1;
}


int main(){
    int q, n;
    int S[MAX];

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &S[i]);

    q = partition(S, 0, n-1);

    for(int i=0; i<n; i++){
        if(i==q) cout << "|";
        cout << S[i];
        if(i==q) cout << "|";
        cout << " ";
    }
    cout << "\n";

    return 0;
}