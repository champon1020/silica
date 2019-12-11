#include <iostream>
#define MAX 250

using namespace std;


int parent(int i){
    return i / 2;
}

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

int main(){
    int h, k, a[MAX+1];
    cin >> h;
    for(int i=1; i<=h; i++){
        cin >> a[i];
    }
    
    for(int i=1; i<=h; i++){
        cout << "node " << i << ": ";
        cout << "key " << a[i] << ": ";
        if(parent(i) >= 1){
            cout << "parent key = " << a[parent(i)] << ", ";
        }
        if(left(i) <= h){
            cout << "left key = " << a[left(i)] << ", ";
        }
        if(right(i) <= h){
            cout << "right key = " << a[right(k)] << ", ";
        }
        cout << endl;
    }
    return 0;
}