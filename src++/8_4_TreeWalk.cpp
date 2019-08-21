/* smaple

9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1

*/

#include <iostream>
#define MAX 25
#define NIL -1

using namespace std;


struct Node{
    int p, l, r;
};

Node T[MAX];

void init(int n){
    for(int i=0; i<n; i++){
        T[i].l = T[i].r = T[i].p = NIL;
    }
}

void preParse(int i){
    if(i == NIL){
        return;
    }
    cout << i << " ";
    preParse(T[i].l);
    preParse(T[i].r);
}

void inParse(int i){
    if(i == NIL){
        return;
    }
    inParse(T[i].l);
    cout << i << " ";
    inParse(T[i].r);
}

void postParse(int i){
    if(i == NIL){
        return;
    }
    postParse(T[i].l);
    postParse(T[i].r);
    cout << i << " ";
}

int main(){
    int n, id, left, right, root;
    cin >> n;
    init(n);
    for(int i=0; i<n; i++){
        cin >> id >> left >> right;
        T[id].l = left;
        T[id].r = right;
        T[left].p = T[right].p = id;
    }
    for(int i=0; i<n; i++){
        if(T[i].p == NIL){
            root = i;
        }
    }
    cout << "\nPre\n";
    preParse(root);
    cout << "\nIn\n";
    inParse(root);
    cout << "\nPost\n";
    postParse(root);
    cout << "\n";
    return 0;
}