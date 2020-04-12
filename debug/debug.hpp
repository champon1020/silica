#ifndef INCLUDE_DEBUG_HPP
#define INCLUDE_DEBUG_HPP

#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace dbg {
    using ll = long long;

    class Debug {
    public:
        Debug(){}
        template<typename T>
        void vd(vector<T> vec);
        template<typename T>
        void vd2(vector<vector<T>> vec);
        template<typename T>
        void ad(T *arr, ll n);
        template<typename T, size_t N>
        void ad2(T (&arr)[N], ll n);
        template<typename T>
        void md(T mp);
    };

    template<typename T>
    void Debug::vd(vector<T> vec) {
        for (auto vv : vec) cout << vv << " ";
        cout << endl;
    }

    template<typename T>
    void Debug::vd2(vector<vector<T>> vec) {
        for (auto vv : vec) {
            for (auto vvv : vv) cout << vvv << " ";
            cout << endl;
        }
    }

    template<typename T>
    void Debug::ad(T *arr, ll n) {
        for (int i = 0; i <= n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    template<typename T, size_t N>
    void Debug::ad2(T (&arr)[N], ll n) {
        for (int i = 0; i <= N; i++) for (int j = 0; j <= n; j++) cout << arr[i][j] << " ";
        cout << endl;
    }

    template<typename T>
    void Debug::md(T mp) {
        cout << "key : value" << endl;
        for (auto const &m : mp) cout << m.first << " : " << m.second << endl;
        cout << endl;
    }

}

#endif //INCLUDE_DEBUG_HPP
