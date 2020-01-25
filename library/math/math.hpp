#ifndef DEFINE_MATH_HPP
#define DEFINE_MATH_HPP

class Math
{
    ll mod = 1e9+7;
  public:
    template<typename T> int keta(T num);
    template<typename T1, typename T2> ll gcd(T1 a, T2 b);
    template<typename T1, typename T2> ll lcm(T1 a, T2 b);
    template<typename T1, typename T2> ll powmod(T1 num1, T2 num2);
    template<typename T1, typename T2> ll powl(T1 a, T2 b);
};

#endif //DEFINE_MATH_HPP

template<typename T1, typename T2>
ll Math::gcd(T1 a, T2 b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

template<typename T1, typename T2>
ll Math::lcm(T1 a, T2 b){
    return a*(b/gcd(a, b));
}

template<typename T>
int Math::keta(T num){
    T k=0;
    while(num>0){
        num/=10;
        k++;
    }
    return k;
}

template<typename T1, typename T2>
ll Math::powmod(T1 num1, T2 num2){
    ll res = 1;
    while(num2 > 0){
        res *= num1;
        res %= mod;
        num2--;
    }
    return res%mod;
}

template<typename T1, typename T2>
ll Math::powl(T1 a, T2 b){
    ll res = 1;
    while(b > 0){
        res *= a;
        b--;
    }
    return res;
}