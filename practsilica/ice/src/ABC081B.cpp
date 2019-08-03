#include <iostream>
#include <cstdio>

using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int count = 0;
    int flag = 0;
    while(flag==0){
        for(int i=0; i<n; i++){
            if(a[i]%2 == 0){
                a[i] /= 2;
            }else{
                flag = 1;
                break;
            }
        }
        if(flag){
            break;
        }else{
            count++;
        }
    }
    cout << count << endl;
    return 0;
}