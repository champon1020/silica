#include <iostream>

using namespace std;


int main(){
    int n, S[10000];
    int q, T[500];
    int count = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for(int i=0; i<q; i++){
        scanf("%d", &T[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<q; j++){
            if(S[i] == T[j]){
                count++;
            }
        }
    }

    if(count > 0){
        printf("%d", count);
    
    }else{
        printf("Common number is nothing");
    }
}