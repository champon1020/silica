/* sample

10
insert 30
insert 88
insert 12
insert 1
insert 20
find 12
insert 17
insert 25
find 16
print

*/

#include <iostream>
#include <string>

using namespace std;


struct Node {
    int key;
    Node *p, *l, *r;
};

Node *root, *NIL;

void insert(int k){
    Node *x = root;
    Node *y = NIL;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->l = NIL;
    z->r = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->l;
        }else{
            x = x->r;
        }
    }

    z->p = y;
    if(y == NIL){
        root = z;
    }else{
        if(z->key < y->key){
            y->l = z;
        }else{
            y->r = z;
        }
    }
}

// Node *find(Node *u, int k){
//     while(u != NIL && u->key != k){
//         if(k < u->key){
//             u = u->l;
//         }else{
//             u = u->r;
//         }
//     }
//     return u;
// }

void find(Node *u, int k){
    while(u != NIL){
        if(k < u->key){
            u = u->l;
        }else if(k > u->key){
            u = u->r;
        }else{
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
    return;
}

void preorder(Node *u){
    if(u == NIL){
        return;
    }
    cout << u->key << " ";
    preorder(u->l);
    preorder(u->r);
}

void inorder(Node *u){
    if(u == NIL){
        return;
    }
    inorder(u->l);
    cout << u->key << " ";
    inorder(u->r);
}

int main(){
    int n, k;
    string op;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> op;
        if(op == "insert"){
            cin >> k;
            insert(k);
        }
        if(op == "find"){
            cin >> k;
            find(root, k);
        }
        if(op == "print"){
            inorder(root);
            cout << "\n";
            preorder(root);
            cout << "\n";
        }
    }
}