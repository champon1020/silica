#ifndef INCLUDE_MINT_HPP
#define INCLUDE_MINT_HPP

class mint
{
public:
    const int mod = 1e9+7;
    typedef long long ll;
    ll a;
    mint(ll a=0):a((a%mod + mod)%mod){}
    mint operator-() const { return mint(-a); }
    mint operator+(const mint rhs) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint rhs) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint rhs) const {
        mint res(*this);
        return res*=a;
    }
    mint& operator+=(const mint rhs) {
        if((a += rhs.a) >= mod) a -= mod;
        return *this;
    }
    mint& operator-=(const mint rhs) {
        if((a += mod-rhs.a) >= mod) a -= mod;
        return *this;
    }
    mint& operator*=(const mint rhs) {
        (a *= rhs.a) %= mod;
        return *this;
    }
    mint pow(ll t) const {
        if(!t) return 1;
        mint b = pow(t>>1);
        b *= b;
        if(t&1) b *= *this;
        return b;
    }

    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint rhs) {
        return (*this) *= rhs.inv();
    }
    mint operator/(const mint rhs) const {
        mint res(*this);
        return res/=rhs;
    }
};

#endif //INCLUDE_MINT_HPP
