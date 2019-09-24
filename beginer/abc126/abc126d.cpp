#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


Int n;
Int color[100001];
Int graph[100001][100001];

void dfs(Int u){
    for(Int i=1; i<=n; i++){
        if(graph[u][i] == 0) continue;
        if(graph[u][i]%2 == 0){
            color[i] = color[u];
        }else{
            color[i] = color[u]==0 ? 1 : 0;
        }
        dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int u, v, w;
    cin >> n;
    for(Int i=0; i<n-1; i++){
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    for(Int i=1; i<=n; i++){
        color[i] = 0;
    }
    
    dfs(1);

    for(Int i=1; i<=n; i++){
        cout << color[i] << endl;
    }
    return 0;
}