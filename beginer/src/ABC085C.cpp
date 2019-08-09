#include <iostream>

using namespace std;


struct money {
    int x;
    int y;
    int z;
};

money m;



int checkY(int n, int Y, const int x, int y){
    for(int i=y; i>=0; i--){
        int sum = x*10000+i*5000+(n-x-i)*1000;
        if(sum == Y){
            m.x = x;
            m.y = i;
            m.z = n-x-i;
            return 1;
        }
    }
    return -1;
}


int check(int n, int Y){
    if(10000*n < Y){
        return -1;
    }
    if(1000*n > Y){
        return -1;
    }
    for(int i=n; i>=0; i--){
        int sum = i*10000+(n-i)*5000;
        if(sum == Y){
            m.x = i;
            m.y = n-i;
            m.z = 0;
            return 1;
        }else{
            int result = checkY(n, Y, i, n-i);
            if(result == 1){
                return 1;
            }
        }
    }
    return -1;
}


int main(){
    int n, Y;
    cin >> n >> Y;

    int result = check(n, Y);
    if(result == -1){
        cout << "-1 -1 -1" << endl;
    }else{
        cout << m.x << " " << m.y << " " << m.z << endl;
    }
    return 0;
}