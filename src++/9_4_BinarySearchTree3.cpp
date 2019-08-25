#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *p, *l, *r;
};

Node *root, *NIL;

void insert(int k){
    Node *x = root;
    Node *y = NIL;
    Node *z = (Node *)malloc(sizeof(Node));
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

Node *find(Node *u, int k){
    while(u != NIL && u->key != k){
        if(k < u->key){
            u = u->l;
        }else{
            u = u->r;
        }
    }
    return u;
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

}