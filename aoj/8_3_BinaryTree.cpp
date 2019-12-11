/* sample

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


struct Node {
    int p, l, r;
};

Node T[MAX];
int D[MAX], H[MAX];

void init(int n){
    for(int i=0; i<n; i++){
        T[i].p = T[i].l = T[i].r = NIL;
    }
}

int calcChild(int i){
    int cnt = 0;
    if(T[i].l != NIL){
        cnt++;
    }
    if(T[i].r != NIL){
        cnt++;
    }
    return cnt;
}

void dep(int i, int d){
    D[i] = d;
    if(T[i].l != NIL){
        dep(T[i].l, d+1);
    }
    if(T[i].r != NIL){
        dep(T[i].r, d+1);
    }
}

int height(int i){
    int h1 = 0, h2 = 0;
    if(T[i].l != NIL){
        h1 = height(T[i].l) + 1;
    }
    if(T[i].r != NIL){
        h2 = height(T[i].r) + 1;
    }
    return H[i] = (h1 > h2) ? h1 : h2;
}

void print(int n){
    for(int i=0; i<n; i++){
        cout << "node " << i << " : ";
        int parent = T[i].p;
        cout << "parent " << parent << " : ";
        cout << "sibling ";
        if(parent == NIL){
            cout << NIL;
        }else if(T[parent].l != i && T[parent].l != NIL){
            cout << T[parent].l;
        }else if(T[parent].r != i && T[parent].r != NIL){
            cout << T[parent].r;
        }else{
            cout << NIL;
        }
        cout << " : ";
        cout << "deg " << calcChild(i) << " : ";
        cout << "dep " << D[i] << " : ";
        cout << "h " << H[i] << " : ";

        if(T[i].p == NIL){
            cout << "root";
        }else if (T[i].l == NIL && T[i].r == NIL){
            cout << "leaf";
        }else{
            cout << "internal node";
        }
        cout << endl;
    }
}

int main(){
    int n, id, left, right, root;
    cin >> n;
    init(n);
    for(int i=0; i<n; i++){
        cin >> id >> left >> right;
        T[id].l = left;
        T[i].r = right;
        T[left].p = T[right].p = id;
    }
    for(int i=0; i<n; i++){
        if(T[i].p == NIL){
            root = i;
            break;
        }
    }
    dep(root, 0);
    height(root);
    print(n);
    return 0;
}