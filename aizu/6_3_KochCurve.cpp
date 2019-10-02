#include <iostream>
#include <cstdio>
#include <cmath>

#define PI 3.14159265

using namespace std;

struct Coord {
    double x;
    double y;
};


// koch(min, max)
void koch(Coord c1, Coord c2, int n){
    printf("%d", n);
    if(n == 0) return;

    Coord c1_, c2_, mid;

    c1_.x = (c2.x + 2*c1.x)/3;
    c1_.y = (c2.y + 2*c1.y)/3;
    c2_.x = (2*c2.x + c1.x)/3;
    c2_.y = (2*c2.y + c1.y)/3;

    mid.x = (c2_.x - c1_.x)*cos(PI/2) - (c2_.x - c1_.x)*sin(PI/2) + c1_.x;
    mid.y = (c2_.y - c1_.y)*cos(PI/2) + (c2_.y - c1_.y)*sin(PI/2) + c1_.y;

    printf("%.8f %.8f\n", c1_.x, c1_.y);
    printf("%.8f %.8f\n", mid.x, mid.y);
    printf("%.8f %.8f\n", c2_.x, c2_.y);

    koch(c1, c1_, n-1);
    koch(c1_, mid, n-1);
    koch(mid, c2_, n-1);
    koch(c2_, c2, n-1);
}


int main(){
    int n;
    scanf("%d", &n);

    Coord c1, c2;
    c1.x = 0.0;
    c1.y = 0.0;
    c2.x = 100.0;
    c2.y = 0.0;

    printf("%.8f %.8f\n", c1.x, c1.y);
    koch(c1, c2, n);
    printf("%.8f %.8f\n", c2.x, c2.y);
}