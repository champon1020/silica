#ifndef INCLUDE_DEBUG_HPP
#define INCLUDE_DEBUG_HPP

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class debug
{
public:
    typedef long long ll;
    template<typename T> void vd(vector<T> vec);
    template<typename T> void vd2(vector<vector<T>> vec);
    template<typename T> void vpd(vector<pair<int, int>> vec);
    template<typename T> void ad(T *arr, ll n);
    template<typename T, size_t N> void ad2(T (&arr)[N], ll n);
    template<typename T> void md(T mp);
};

#endif //INCLUDE_DEBUG_HPP

template<typename T> void debug::vd(vector<T> vec)
{
    for(auto vv : vec) cout << vv << " ";
    cout << endl;
}

template<typename T> void debug::vd2(vector<vector<T>> vec)
{
    for(auto vv : vec) for(auto vvv : vv) cout << vvv << " ";
    cout << endl;
}

template<typename T> void debug::vpd(vector<pair<int, int>> vec) {
    for(auto const& vv : vec) {
        cout << vv.first << " " << vv.second << endl;
    }
    cout << endl;
}

template<typename T> void debug::ad(T *arr, ll n)
{
    for(int i=0; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}

template<typename T, size_t N> void debug::ad2(T (&arr)[N], ll n)
{
    for(int i=0; i<=N; i++) for(int j=0; j<=n; j++) cout << arr[i][j] << " ";
    cout << endl;
}

template<typename T> void debug::md(T mp)
{
    cout << "key : value" << endl;
    for(auto const& m : mp) cout << m.first << " : " << m.second << endl;
    cout << endl;
}