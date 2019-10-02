/* sample

6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0

*/

#include <iostream>
#include <vector>

#define MAX 100

using namespace std;


int n;
int timet;
int m[MAX][MAX];
int stts[MAX];
int dst[MAX];
int dstf[MAX];

void init(int n){
    for(int i=0; i<n; i++){
        stts[i] = 0;
        for(int j=0; j<n; j++){
            m[i][j] = 0;
        }
    }
}

void dfs(int u){
    stts[u] = 1;
    dst[u] = ++timet;
    for(int v=0; v<n; v++){
        if(m[u][v] == 0){
            continue;
        }
        if(dst[v] == 0){
            dfs(v);
        }
    }
    stts[u] = 2;
    dstf[u] = ++timet;
}

int main(){
    int u, k;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> u >> k;
        for(int j=0; j<k; j++){
            int tmp;
            cin >> tmp;
            m[i][tmp-1] = 1;
        }
    }
    timet = 0;
    dfs(0);
    for(int i=0; i<n; i++){
        cout << i+1 << " " << dst[i] << " " << dstf[i] << endl;
    }
    return 0;
}