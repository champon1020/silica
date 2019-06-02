#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


struct Node {
    int key;
    Node *prev, *next;
};


Node *nil;


void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}


void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;

    x->next = nil->next;
    x->next->prev = x;
    nil->next = x;
    x->prev = nil;    
}


Node* listSearch(int key){
    Node *cur = nil->next;
    
    while(cur != nil && cur->key != key){
        cur = cur->next;
    }

    return cur;
}


void deleteNode(Node *t){
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}


void deleteFirst(){
    deleteNode(nil->next);
}


void deleteLast(){
    deleteNode(nil->prev);
}


void deleteKey(int key){
    deleteNode(listSearch(key));
}


int main(void){
    int num;
    int key;
    int count = 0;
    char op[15];

    init();

    scanf("%d", &num);
    while(count < num){
        scanf("%s", op);
        scanf("%d", &key);

        if(!strcmp(op, "insert\0")){
            insert(key);

        }else if(!strcmp(op, "delete\0")){
            deleteKey(key);

        }else if(!strcmp(op, "deleteFirst\0")){
            deleteFirst();

        }else if(!strcmp(op, "deleteLast\0")){
            deleteLast();

        }else{
            printf("This order is not appropriate.\n");
            continue;
        }

        count++;
    }

    Node *cur = nil->next;
    while(cur != nil){
        printf("%d", cur->key);
        cur = cur->next;
    }
}