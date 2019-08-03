#include <iostream>

using namespace std;


int fifty(int x, int c){
    if(x/50 <= c){
        return 1;
    }else{
        return 0;
    }
}


int fiftyAndHundred(int x, int b, int c){
    int count = fifty(x, c);
    for(int i=1; i<=b; i++){
        if(x < 100*i){
            break;
        }else{
            count += fifty(x-100*i, c);
        }
    }
    return count;
}


int fiveHundredAndHundredAndfifty(int x, int a, int b, int c){
    int count = fiftyAndHundred(x, b, c);
    for(int i=1; i<=a; i++){
        if(x < 500*i){
            break;
        }else{
            count += fiftyAndHundred(x-500*i, b, c);
        }
    }
    return count;
}


int main(){
    int a,b,c,x;
    cin >> a >> b >> c >> x;

    cout << fiveHundredAndHundredAndfifty(x, a, b, c) << endl;
    return 0;
}