#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;


double calcMin(double x, double y, double x_, double y_){
    return sqrt((x-x_)*(x-x_) + (y-y_)*(y-y_));
}


int main(){
    int n;
    cin >> n;
    double x[n], y[n];
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    double max = 0.0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j==i){
                continue;
            }
            double l = calcMin(x[i], y[i], x[j], y[j]);
            max = l > max ? l : max;
        }
    }
    printf("%8lf", max);
    return 0;
}