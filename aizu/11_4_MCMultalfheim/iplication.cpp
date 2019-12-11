/* sample

6
30 35
35 15
15 5
5 10
10 20
20 25

*/

#include <iostream>
#define N 100
using namespace std;

int getMin(int a, int b){
    return (a < b) ? a : b;
}

int main(){
    int n, p[N+1], m[N+1][N+1];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p[i] >> p[i+1];
    }

    // i == j
    for(int i=1; i<=n; i++){
        m[i][i] = 0;
    }
    // i != j
    for(int l=2; l<=n; l++){
        for(int i=1; i<=n-l+1; i++){
            int j = i+l-1;
            m[i][j] = (1 << 21);
            for(int k=i; k<=j-1; k++){
                m[i][j] = getMin(m[i][j], m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << m[1][n] << endl;
    return 0;
}