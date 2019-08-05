#include <iostream>
#define N 100

using namespace std;


int init(int d[]){
    for(int i=0; i<=N; i++){
        d[i] = 0;
    }
}

int main(){
    int n;
    int a[N];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int d[N+1];
    int sum = 0;
    init(d);
    for(int i=0; i<n; i++){
        if(d[a[i]] == 0){
            d[a[i]]++;
            sum++;
        }
    }
    cout << sum << endl;
}