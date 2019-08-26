/*

insert 8
insert 2
extract
insert 10
extract
insert 11
extract
extract
end

*/


#include <iostream>
#include <string>
#define MAX 2000000
#define INF (1<<30)

using namespace std;

int h;
int a[MAX+1];

int parent(int i){
    return i/2;
}

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

void maxHeapify(int i){
    int largest;
    int l = left(i);
    int r = right(i);
    if(l <= h && a[l] > a[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= h && a[r] >= a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        maxHeapify(largest);
    }
}  

int extract(){
    if(h < 1){
        return -INF;
    }
    int tmp = a[1];
    a[1] = a[h--];
    maxHeapify(1);
    return tmp;
}

void insert(int k){
    h++;
    a[h] = -INF;
    if(k < a[h]){
        return;
    }
    a[h] = k;
    int i = h;
    while(i > 1 && a[parent(i)] < a[i]){
        swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}

int main(){
    string op;
    int k;
    h = 0;

    while(true){
        cin >> op;
        if(op == "end"){
            break;
        }
        if(op == "insert"){
            cin >> k;
            insert(k);
        }
        if(op == "extract"){
            int out = extract();
            cout << out << endl;
        }
    }   
    return 0; 
}