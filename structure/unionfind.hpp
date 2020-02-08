#ifndef DEFINE_UNIONFIND_HPP
#define DEFINE_UNIONFIND_HPP

#include <vector>
using namespace std;

template<typename T>
class UnionFind
{
  public:
    vector<T> par;
    vector<T> rank;
    vector<T> size;

    UnionFind(int n);

    T find(T x);
    void unite(T x, T y);
    bool same(T x, T y);
    T getsize(T x);
    int rootCount(int n);
};

#endif //DEFINE_UNIONFIND_HPP

template<typename T>
UnionFind<T>::UnionFind(int n):par(n, 0),rank(n, 0),size(n, 1)
{
    iota(par.begin(), par.end(), 0);
}

template<typename T>
T UnionFind<T>::find(T x)
{
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

template<typename T>
void UnionFind<T>::unite(T x, T y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]){
        par[x] = y;
        size[y] += size[x];
    }else{
        par[y] = x;
        size[x] += size[y];
        if(rank[x] == rank[y]) rank[x]++;
    }
}

template<typename T>
bool UnionFind<T>::same(T x, T y)
{
    return find(x) == find(y);
}

template<typename T>
T UnionFind<T>::getsize(T x)
{
    return size[find(x)];
}

template<typename T>
int UnionFind<T>::rootCount(int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(i == par[i]) cnt++;
    }
    return cnt;
}


// verify
// https://atc001.contest.atcoder.jp/tasks/unionfind_a
