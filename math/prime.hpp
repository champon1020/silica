#ifndef INCLUDE_FACTOR_HPP
#define INCLUDE_FACTOR_HPP

#include <vector>
#include <map>
using namespace std;

namespace prime {

    using ll = long long;

    class prime {
    public:
        template<typename T>
        map<ll, ll> factor(T val);
        template<typename T>
        bool isPrime(T val);
    };

    template<typename T>
    map<ll, ll> prime::factor(T val) {
        vector<T> f;
        for (ll i = 2; i * i <= val; i++) {
            while (val % i == 0) {
                f.push_back(i);
                val /= i;
                if (val == 0) break;
            }
        }
        if (val > 1) f.push_back(val);
        map<ll, ll> res;
        for (auto const &e : f) {
            res[e]++;
        }
        return res;
    }

    template<typename T>
    bool prime::isPrime(T val) {
        for (ll i = 2; i * i <= val; i++) {
            if (val % i == 0) return false;
        }
        return true;
    }

}

#endif //INCLUDE_FACTOR_HPP