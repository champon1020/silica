#include <iostream>

using namespace std;

int n;
int t[100000], x[100000], y[100000];


int checkTooFar(int t, int x, int y){
    return t < x+y ? -1 : 1;
}


int check(int i){
    if(t[i]%2==0 && (x[i]+y[i])%2!=0){
        return -1;
    }
    if(t[i]%2!=0 && (x[i]+y[i])%2==0){
        return -1;
    }
    if(i==0){
        return checkTooFar(t[i], x[i], y[i]);
    }else{
        return checkTooFar(t[i]-t[i-1], x[i]-x[i-1], y[i]-y[i-1]);
    }
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t[i] >> x[i] >> y[i];
    }

    for(int i=0; i<n; i++){
        int result = check(i);
        if(result == -1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}