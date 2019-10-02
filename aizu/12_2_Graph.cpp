/* sample

4
1 2 2 4
2 1 4
3 0
4 1 3

*/

#include <iostream>
#define MAX 100

using namespace std;


int m[MAX][MAX];

void init(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            m[i][j] = 0;
        }
    }
}

int main(){
    int n;
    int u, k;
    cin >> n;
    init(n);
    for(int i=0; i<n; i++){
        cin >> u >> k;
        for(int j=0; j<k; j++){
            int tmp;
            cin >> tmp;
            m[i][tmp-1] = 1;
        }
    }

    cout << endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}