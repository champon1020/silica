#ifndef INCLUDE_MINT_HPP
#define INCLUDE_MINT_HPP

namespace mint {

    using ll = long long;

    class Mint {
    public:
        ll v;
        ll mod;

        Mint(ll v=0, ll mod=ll(1e9)+7) : mod(mod), v((v % mod + mod) % mod) {}

        Mint operator-() const { return Mint(-v); }
        Mint operator+(const Mint rhs) const {
            Mint res(*this);
            return res += rhs;
        }
        Mint operator-(const Mint rhs) const {
            Mint res(*this);
            return res -= rhs;
        }
        Mint operator*(const Mint rhs) const {
            Mint res(*this);
            return res *= rhs;
        }
        Mint &operator+=(const Mint rhs) {
            if ((v += rhs.v) >= mod) v -= mod;
            return *this;
        }
        Mint &operator-=(const Mint rhs) {
            if ((v += mod - rhs.v) >= mod) v -= mod;
            return *this;
        }
        Mint &operator*=(const Mint rhs) {
            (v *= rhs.v) %= mod;
            return *this;
        }
        Mint pow(ll t) const {
            if (!t) return 1;
            Mint b = pow(t >> 1);
            b *= b;
            if (t & 1) b *= *this;
            return b;
        }
        Mint inv() const {
            return pow(mod - 2);
        }
        Mint &operator/=(const Mint rhs) {
            return (*this) *= rhs.inv();
        }
        Mint operator/(const Mint rhs) const {
            Mint res(*this);
            return res /= rhs;
        }
    };

}

#endif //INCLUDE_MINT_HPP
