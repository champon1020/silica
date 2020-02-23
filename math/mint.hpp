#ifndef INCLUDE_MINT_HPP
#define INCLUDE_MINT_HPP

namespace mint {
    using ll = long long;
    const ll mod = 1e9+7;

    class mint {
    public:
        ll v;

        mint(ll a = 0) : v((v % mod + mod) % mod) {}

        mint operator-() const { return mint(-v); }
        mint operator+(const mint rhs) const {
            mint res(*this);
            return res += v;
        }
        mint operator-(const mint rhs) const {
            mint res(*this);
            return res -= v;
        }
        mint operator*(const mint rhs) const {
            mint res(*this);
            return res *= v;
        }
        mint &operator+=(const mint rhs) {
            if ((v += rhs.v) >= mod) v -= mod;
            return *this;
        }
        mint &operator-=(const mint rhs) {
            if ((v += mod - rhs.v) >= mod) v -= mod;
            return *this;
        }
        mint &operator*=(const mint rhs) {
            (v *= rhs.v) %= mod;
            return *this;
        }
        mint pow(ll t) const {
            if (!t) return 1;
            mint b = pow(t >> 1);
            b *= b;
            if (t & 1) b *= *this;
            return b;
        }
        mint inv() const {
            return pow(mod - 2);
        }
        mint &operator/=(const mint rhs) {
            return (*this) *= rhs.inv();
        }
        mint operator/(const mint rhs) const {
            mint res(*this);
            return res /= rhs;
        }
    };

}

#endif //INCLUDE_MINT_HPP
