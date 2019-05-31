#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


class Deal{
    public:
    char name[10];
    int time;
};


int main(void){
    int n, q;
    int first, last;
    int time=0;

    vector<Deal> queue;

    scanf("%d %d", n, q);
    for(int i=0; i<n; i++){
        Deal buf;
        scanf("%s %d", buf.name, buf.time);
        queue.push_back(buf);
    }

    first = 0;
    last = n-1;

    do{
        if(queue[first].time <= q){
            time += queue[first].time;
            printf("%s %d\n", queue[first].name, time);
        }else{
            time += q;
            queue[first].time -= q;
            queue.push_back(queue[first]);
            queue.erase(queue.begin());
        }
    }while(!queue.empty());

    return 0;
}