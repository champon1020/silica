#ifndef INCLUDE_DEBUG_HPP
#define INCLUDE_DEBUG_HPP

#define TO_STRING(varName) # varName
#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace dbg {
    using ll = long long;

    class Debug {
        void prefix(string s){
            cout << "\033[7m\033[35m" << " DEBUG " << "\033[0m\033[35m"
            << " " << s << "\033[0m" << endl;
        }
    public:
        Debug(){}
        // vector d1
        template<typename T>
        void print(vector<T> &vec);

        // vector tuple
        template<typename T1, typename T2>
        void print(vector<pair<T1, T2>>& vec, int idx = 0);

        // vector d2
        template<typename T>
        void print(vector<vector<T>>& vec);

        // vector d2
        template<typename T>
        void print(vector<vector<vector<T>>>& vec);

        // vector array d1
        template<typename T>
        void print(T *arr, ll n);

        // vector array d2
        template<typename T>
        void print(T *arr, int n, int m);

        // set
        template<typename T>
        void print(set<T>& st);

        // vector map or set
        template<typename T>
        void print(T cont);
    };

    template<typename T>
    void Debug::print(vector<T>& vec) {
        prefix("vector");
        for (auto& v : vec) cout << v << " ";
        cout << endl;
    }

    template<typename T1, typename T2>
    void Debug::print(vector<pair<T1, T2>>& vec, int idx) {
        prefix("vector pair");
        for (auto& v : vec) cout << (!idx ? get<0>(v) : get<1>(v)) << " ";
        cout << endl;
    }

    template<typename T>
    void Debug::print(vector<vector<T>>& vec) {
        prefix("vector d2");
        for (auto& vv : vec) {
            for (auto& v : vv) cout << v << " ";
            cout << endl;
        }
    }

    template<typename T>
    void Debug::print(vector<vector<vector<T>>>& vec) {
        prefix("vector d3");
        for(auto& vvv : vec) {
            cout << "[";
            for(int i=0; i<vvv.size(); i++) {
                if(i) cout << " ";
                for(int j=0; j<vvv[i].size(); j++) {
                    if(j) cout << " ";
                    cout << vvv[i][j];
                }
                if(i != vvv.size()-1) cout << endl;
            }
            cout << "]" << endl;
        }
    }

    template<typename T>
    void Debug::print(T *arr, ll n) {
        prefix("array");
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    template<typename T>
    void Debug::print(T *arr, int n, int m) {
        prefix("array d2");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    template<typename T>
    void Debug::print(set<T>& st) {
        prefix("set");
        for(auto& e : st) cout << e << " ";
        cout << endl;
    }

    template<typename T>
    void Debug::print(T cont) {
        prefix("key value");
        for (auto& e : cont)
            cout << e.first << " : " << e.second << endl;
        cout << endl;
    }

}

#endif //INCLUDE_DEBUG_HPP
