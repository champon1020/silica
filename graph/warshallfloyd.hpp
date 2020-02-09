#ifndef DEFINE_WARSHALLFLOYD_HPP
#define DEFINE_WARSHALLFLOYD_HPP

#include <vector>
using namespace std;

class WarshallFloyd
{
    typedef long long ll;
    const ll inf = 4e18;
public:
    int n;
    vector<vector<ll>> g;

    WarshallFloyd(int n);

    void add(int from, int to, ll cost);
    void build();
    ll result(int from, int to);
};

#endif //DEFINE_WARSHALLFLOYD_HPP

WarshallFloyd::WarshallFloyd(int n):n(n)
{
    g.assign(n, vector<ll>(n, inf));
    for(int i=0; i<n; i++){
        g[i][i] = 0;
    }
}

void WarshallFloyd::add(int from, int to, ll cost)
{
    g[from][to] = cost;
}

void WarshallFloyd::build()
{
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

ll WarshallFloyd::result(int from, int to)
{
    return g[from][to];
}

// verify
// https://atcoder.jp/contests/abc012/tasks/abc012_4