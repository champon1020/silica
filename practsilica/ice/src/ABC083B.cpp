#include <iostream>
#include <cmath>

using namespace std;


int calcSum(int num){
    int sum = 0;
    while(num){
        int dig = num%10;
        sum += dig;
        num /= 10;
    }
    return sum;
}


int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int sum = 0;
    for(int i=1; i<=n; i++){
        int p = calcSum(i);
        if(a <= p && p <= b){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}