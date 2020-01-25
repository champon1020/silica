#ifndef DEFINE_SEGTREE_HPP
#define DEFINE_SEGTREE_HPP

template<typename T>
class SegmentTree
{
  public:
    T n;
    vector<T> dat;

    SegmentTree(int nn);

    void update(T k, T a);
    T query(T a, T b, T k, T l, T r);
    T getquery(T a, T b);
    T operator[](int i);
};

#endif //DEFINE_SEGTREE_HPP

template<typename T>
SegmentTree<T>::SegmentTree(int nn)
{
    n = 1;
    while(n < nn) n*=2;
    dat.resize(2*n-1, inf);
}

template<typename T>
void SegmentTree<T>::update(T k, T a)
{
    k += n-1;
    dat[k] = a;
    while(k > 0){
        k = (k-1)/2;
        dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
    }
}

template<typename T>
T query(T a, T b, T k, T l, T r)
{
    if(r <= a || b <= l) return inf;
    if(a <= l && r <= b) return dat[k];
    else{
        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }
}

template<typename T>
T getquery(T a, T b)
{
    return query(a, b, 0, 0, n-1);
}

T operator[](int i)
{
    return dat[i+n-1];
}