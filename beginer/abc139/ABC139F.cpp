#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main(){
    int n;
    double x[200], y[200];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    double result;
    double max = 0;
    double xx, yy;
    for(int bit=0; bit < (1<<n); bit++){
        xx = 0;
        yy = 0;
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                xx += x[i];
                yy += y[i];
            }
        }
        result = sqrt(pow(xx, 2) + pow(yy, 2));
        max = (result > max) ? result : max;
    }
    printf("%.20lf", max);
    return 0;
}