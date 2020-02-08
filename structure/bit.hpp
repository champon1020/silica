#ifndef DEFINE_BIT_HPP
#define DEFINE_BIT_HPP

#include <vector>
using namespace std;

template<typename T>
class Bit
{
  public:
    T n;
    vector<T> bit;

    Bit(T nn, T e);

    T sum(T i);
    void add(T i, T x);
};

#endif //DEFINE_BIT_HPP

template<typename T>
Bit<T>::Bit(T nn, T e):n(nn),bit(nn+1, e){}

template<typename T>
T Bit<T>::sum(T i)
{
    T s = 0;
    while(i > 0){
        s += bit[i];
        i -= i&-i;
    }
    return s;
}

template<typename T>
void Bit<T>::add(T i, T x)
{
    while(i <= n){
        bit[i] += x;
        i += i&-i;
    }
}