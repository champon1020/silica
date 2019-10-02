/* smaple

8
insert 30
insert 88
insert 12
insert 1
insert 20
insert 17
insert 25
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
    z->r = NIL;
    z->l = NIL;

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

void preorder(Node *root){
    if(root == NIL){
        return;
    }
    cout << root->key << " ";
    preorder(root->l);
    preorder(root->r);
}

void inorder(Node *root){
    if(root == NIL){
        return;
    }
    inorder(root->l);
    cout << root->key << " ";
    inorder(root->r);
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
        if(op == "print"){
            preorder(root);
            cout << "\n";
            inorder(root);
            cout << "\n";
        }
    }
    return 0;
}