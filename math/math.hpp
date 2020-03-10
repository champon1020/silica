#ifndef DEFINE_MATH_HPP
#define DEFINE_MATH_HPP

namespace math {

    using ll = long long;
    ll mod = ll(1e9) + 7;

    class Math {
    public:
        Math() {}
        ll keta(ll num);
        ll gcd(ll a, ll b);
        ll lcm(ll a, ll b);
        ll powm(ll num1, ll num2);
    };

    ll Math::gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    ll Math::lcm(ll a, ll b) {
        return a * (b / gcd(a, b));
    }

    ll Math::keta(ll num) {
        ll k = 0;
        while (num > 0) {
            num /= 10;
            k++;
        }
        return k;
    }

    ll Math::powm(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) (res *= a) %= mod;
            (a *= a) %= mod;
            b >>= 1;
        }
        return res;
    }

}

#endif //DEFINE_MATH_HPP
