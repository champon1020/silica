#ifndef INCLUDE_FACTOR_HPP
#define INCLUDE_FACTOR_HPP

#include <vector>
#include <map>
using namespace std;

namespace factor {

    using ll = long long;

    class Factor {
    public:
        Factor()= default;

        // 素因数分解(Map)
        template<typename T>map<ll, ll> factorMap(T n);

        template<typename T>
        void factorMapAdd(T n, map<T, T> *mp);

        // 素因数分解(Vector)
        template<typename T> vector<ll> factorVec(T n);

        // 約数(Vector)
        template<typename T> vector<ll> divisor(T n);
    };

    template<typename T>
    map<ll, ll> Factor::factorMap(T n) {
        map<ll, ll> res;
        ll buf = n;
        for (ll i = 2; i*i<=n; i++) {
            while (buf % i == 0) {
                res[i]++;
                buf /= i;
            }
        }
        if(buf > 1) res[buf]++;
        return res;
    }

    template<typename T>
    void Factor::factorMapAdd(T n, map<T, T> *mp) {
        ll buf = n;
        for (ll i = 2; i*i<=n; i++) {
            while (buf % i == 0) {
                (*mp)[i]++;
                buf /= i;
            }
        }
        if(buf > 1) (*mp)[buf]++;
    }

    template<typename T>
    vector<ll> Factor::factorVec(T n){
        vector<ll> res;
        ll buf = n;
        for(ll i=2; i*i<=n; i++){
            while(buf%i == 0){
                res.push_back(i);
                buf /= i;
            }
        }
        if(buf > 1) res.push_back(buf);
        return res;
    }

    template<typename T>
    vector<ll> Factor::divisor(T n){
        vector<ll> res;
        for(ll i=1; i*i<=n; i++){
            if(n%i == 0){
                if(i*i == n) res.push_back(i);
                else{
                    res.push_back(i);
                    res.push_back(n/i);
                }
            }
        }
        return res;
    }
}

#endif //INCLUDE_FACTOR_HPP


// verify
// divisor(): https://atcoder.jp/contests/abc161/tasks/abc161_f