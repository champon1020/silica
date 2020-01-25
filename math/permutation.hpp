#ifndef DEFINE_PERMUTATION_HPP
#define DEFINE_PERMUTATION_HPP

template<typename T>
class Perm
{
public:
    ll n;
    vector<T> p;
    vector<vector<T>> p_v;

    Perm(ll n):n(n){}

    void build();
    void build_v();
};
#endif //DEFINE_PERMUTATION_HPP

template<typename T>
void Perm<T>::build()
{
    vector<T> v(n);
    iota(v.begin(), v.end(), 1);
    do {
        ll num = 0;
        for(ll i=0; i<v.size(); i++) num += pow(10, v.size()-(i+1)) * v[i];
        p.push_back(num);
    }while(next_permutation(v.begin(), v.end()));
}

template<typename T>
void Perm<T>::build_v()
{
    ll size = 1;
    for(ll i=0; i<=n; i++) size *= i;
    p_v.assign(size);
    vector<T> v(n);
    iota(v.begin(), v.end(), 1);
    ll ind = 0;
    do {
        for(auto const e : v) p_v[ind].push_back(e);
        ind++;
    }while(next_permutation(v.begin(), v.end()));
}
