//
// Created by champon1020 on 2020/03/10.
//

#ifndef INCLUDE_Z_HPP
#define INCLUDE_Z_HPP

#include <vector>
#include <string>
using namespace std;

namespace Z {

    class Z_Algorithm {
    public:
        // z[i] := s[0:n] と s[i:n] の最長共通接頭辞
        vector<int> z;
        void build(string s);
    };

    void Z_Algorithm::build(string s) {
        int n = s.length();
        z.assign(n, 0);
        z[0] = n;
        int i = 1, j = 0;
        while (i < n) {
            // s[0:j] と s[i:i+j] が同一である限りインクリメント
            while (i + j < n && s[j] == s[i + j]) j++;
            z[i] = j;
            if (j == 0) {
                i++;
                continue;
            }
            // 今までに計算したz配列をコピー
            int k = 1;
            while (k < j && k + z[k] < j) {
                z[i + k] = z[k];
                k++;
            }
            i += k; j -= k;
        }
    }

}

// https://atcoder.jp/contests/abc141/tasks/abc141_e

#endif //INCLUDE_Z_HPP
