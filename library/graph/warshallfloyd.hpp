#ifndef DEFINE_WARSHALLFLOYD_HPP
#define DEFINE_WARSHALLFLOYD_HPP

template<typename T>
class WarshallFloyd {
public:
    int n;
    vector<vector<T>> g;

    WarshallFloyd(int n, T mx);

    void add(int from, int to, T cost);
    void build();
    T result(int from, int to);
};

template<typename T>
WarshallFloyd<T>::WarshallFloyd(int n, T mx):n(n)
{
    g.assign(n, vector<T>(n, mx));
    for(int i=0; i<n; i++){
        g[i][i] = 0;
    }
}

template<typename T>
void WarshallFloyd<T>::add(int from, int to, T cost)
{
    g[from][to] = cost;
}

template<typename T>
void WarshallFloyd<T>::build()
{
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

template<typename T>
T WarshallFloyd<T>::result(int from, int to)
{
    return g[from][to];
}

#endif //DEFINE_WARSHALLFLOYD_HPP

// verify
// https://atcoder.jp/contests/abc012/tasks/abc012_4