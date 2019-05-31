#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

using namespace std;

Deal queue[SIZE];
int first, last;

class Deal{
public:
    char name[10];
    int time;
    
    Deal(){}
    Deal(char *name, int time){
        strcpy(this->name, name);
        this->time = time;
    }
};


void enqueue(Deal d){
    if(last == SIZE-1){
        
    }
}


Deal deque(){
}


int main(void){
    int n, q;
    char name[10];
    int time;

    if(!(cin >> n >> q)){
        exit(1);
    }
    for(int i=0; i<n; i++){
        scanf("%s %d", name, &time);
    }
    printf("\n");

    first = 0;
    last = n-1;
    
    int time = 0;
    do{
        
    }while(0);

    return 0;
}




