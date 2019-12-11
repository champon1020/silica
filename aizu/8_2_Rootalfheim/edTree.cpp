
/* sample

13
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0

*/


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
int D[MAX];

void init(int n){
    for(int i=0; i<n; i++){
        T[i].p = T[i].l = T[i].r = NIL;
    }
}

void dep(int i, int d){
    D[i] = d;
    if(T[i].r != NIL){
        dep(T[i].r, d);
    }
    if(T[i].l != NIL){
        dep(T[i].l, d+1);
    }
}

void print(int n){
    for(int i=0; i<n; i++){
        cout << "node " << i << " : ";
        cout << "parent " << T[i].p << " : ";
        cout << "depth " << D[i] << ":";

        if(T[i].p == NIL){
            cout << "root,";
        }else if(T[i].l == NIL){
            cout << "leaf,";
        }else{
            cout << "internal node,";
        }

        cout << "[";
        for(int j=0, c=T[i].l; c!=NIL; j++, c=T[c].r){
            if(j != 0){
                cout << ",";
            }
            cout << c;
        }
        cout << "]" << endl;
    }
}

int main(){
    int n, id, k, c;
    int left, root;
    cin >> n;
    init(n);
    for(int i=0; i<n; i++){
        cin >> id >> k;
        for(int j=0; j<k; j++){
            cin >> c;
            T[c].p = id; // parent
            if(j == 0){
                T[id].l = c;
            }else{
                T[left].r = c;
            }
            left = c;
        }
    }

    for(int i=0; i<n; i++){
        if(T[i].p == NIL){
            root = i;
        }
    }
    dep(root, 0);

    print(n);
    return 0;
}