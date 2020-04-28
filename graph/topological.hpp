//
// Created by champon1020 on 2020/03/12.
//

#ifndef INCLUDE_TOPOLOGICAL_HPP
#define INCLUDE_TOPOLOGICAL_HPP

#include <vector>
#include <stack>
using namespace std;

namespace topo {

    using ll = long long;

    class Topological_Sort {
    private:
        vector<vector<int>> g;
        vector<int> indeg;  // 頂点iの入次数
        stack<int> s;       // indeg[i]=0 の集合（一番右）
    public:
        int n;
        vector<int> sorted;

        explicit Topological_Sort(int n):n(n) {
            g.assign(n, vector<int>());
            indeg.assign(n, 0);
        }
        void add(int from, int to);
        void build();
    };
}

void topo::Topological_Sort::add(int from, int to) {
    g[from].push_back(to);
}

void topo::Topological_Sort::build() {
    // 入次数計算
    for(auto& out : g) {
        for(auto e : out){
            indeg[e]++;
        }
    }
    // 入次数が0のものをstackに入れる
    for(int i=0; i<n; i++){
        if(indeg[i] == 0) s.push(i);
    }
    // 集合sが0になるまでソート操作を繰り返す
    while(s.size() > 0){
        int u = s.top(); s.pop();
        sorted.push_back(u);
        for(auto& e : g[u]){
            indeg[e]--;
            if(indeg[e] == 0) s.push(e);
        }
    }
}

#endif //INCLUDE_TOPOLOGICAL_HPP

// 参考
// トポロジカルソートについて
// https://www.slideshare.net/hcpc_hokudai/topological-sort-69581002
// 数え上げ(bitDP)
// http://tutuz.hateblo.jp/entry/2018/07/19/234447

// https://atcoder.jp/contests/abc041/tasks/abc041_d
