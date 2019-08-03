#include <iostream>
#include <cstdio>
#define MAX 100000
#define NIL -1

using namespace std;


struct Node{
    int p;     // parent
    int l;     // children's most left
    int r;     // this right
};
struct Node T[MAX];


int main(){
    int n, k, c, id;

    scanf("%d", &n);
    for(int i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;

    for(int i=0; i<n; i++){
        scanf("%d %d", &id, &k);
        for(int j=0; j<k; j++){
            scanf("%d", &c);
            if(j==0) T[id].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }
}