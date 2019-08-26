#include <iostream>

using namespace std;


int h;
int a[500000+1];

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

void maxHeapify(int i){
    int l, r, largest;
    l = left(i);
    r = right(i);
    if(l <= h && a[l] > a[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= h && a[r] > a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        maxHeapify(largest);
    }
}

int main(){
    cin >> h;
    for(int i=1; i<=h; i++){
        cin >> a[i];
    }
    for(int i=h/2; i>=1; i--){
        maxHeapify(i);
    }
    for(int i=1; i<=h; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}