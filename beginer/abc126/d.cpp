#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


class Edge {
    public:
    Int to, weight;
    Edge(Int t, Int w) : to(t), weight(w) {}
};

vector<vector<Edge>> graph(100001);

void dfs(Int u, int color[], Int n, int visit[]){
    visit[u] = 1;
    for(Edge const& e : graph[u]){
        if(visit[e.to] != 0) continue;
        if(e.weight%2 == 0){
            color[e.to] = color[u];
        }else{
            color[e.to] = color[u]==0 ? 1 : 0;
        }
        dfs(e.to, color, n, visit);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n;
    Int u, v, w;
    int color[100001];
    int visit[100001];
    cin >> n;
    for(Int i=0; i<n-1; i++){
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w));
    }
    for(Int i=1; i<=n; i++){
        color[i] = 0;
        visit[i] = 0;
    }
    
    dfs(1, color, n, visit);

    for(Int i=1; i<=n; i++){
        cout << color[i] << endl;
    }
    return 0;
}