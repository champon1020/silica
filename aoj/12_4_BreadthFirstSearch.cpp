/* sample

4
1 2 2 4
2 1 4
3 0
4 1 3

*/

#include <iostream>
#include <queue>
#define MAX 100
#define INF 1<<20

using namespace std;


int n;
int m[MAX][MAX];
int stts[MAX];
int dist[MAX];
queue<int> q;

void bfs(int u){
    stts[u] = 1;
    dist[u] = 0;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(m[u][i] == 0){
                continue;
            }
            if(dist[i] != -INF){
                continue;
            }
            q.push(i);
            dist[i] = dist[u] + 1;
            stts[i] = 1;
        }
        stts[u] = 2;
    }
}

int main(){
    int u, k;
    cin >> n;
    for(int i=0; i<n; i++){
        stts[i] = 0;
        dist[i] = -INF;
        for(int j=0; j<n; j++){
            m[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        cin >> u >> k;
        for(int j=0; j<k; j++){
            int tmp;
            cin >> tmp;
            m[u-1][tmp-1] = 1;
        }
    }

    bfs(0);
    cout << endl;

    for(int i=0; i<n; i++){
        cout << i+1 << " " << ((dist[i] == -INF) ? (-1) : dist[i]) << endl;
    } 
    return 0;
}