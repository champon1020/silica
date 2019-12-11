#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

using namespace std;


class Process{
public:
    char name[10];
    int time;
};


class Queue{
public:
    int head = 0;
    int tail = 0;
    Process Q[100000];
};


Queue queue;


void enqueue(Process p){
    if(queue.head - queue.tail == 1){
        printf("queue is full\n");
        exit(1);
    }
    queue.Q[queue.tail++] = p;
}


Process dequeue(){
    if(queue.head == queue.tail){
        printf("queue is empty\n");
        exit(1);
    }
    Process out;
    out = queue.Q[queue.head++];
    return out;
}


int main(void){
    int n, q;
    Process buf;

    if(!(cin >> n >> q)){
        exit(1);
    }
    for(int i=0; i<n; i++){
        scanf("%s %d", buf.name, &buf.time);
        enqueue(buf);
    }
    printf("\n");

    int time = 0;
    do{
        Process p = dequeue();
        
        if(p.time <= q){
            time += p.time;
            printf("%s %d\n", p.name, time);
        }else if(p.time > q){
            time += q;
            p.time -= 100;
            enqueue(p);
        }
    }while(queue.head != queue.tail);

    return 0;
}




