#include <iostream>

using namespace std;


Node *nil;

struct Node {
    int key;
    Node *prev, *next;
}


void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prv = nil;
}


void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;

    x->next = nil->next;
    
}


int main(void){

}