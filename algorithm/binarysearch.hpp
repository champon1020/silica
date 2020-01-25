#ifndef DEFINE_BINARYSEARCH_HPP
#define DEFINE_BINARYSEARCH_HPP

class binarysearch
{
public:
    auto bs;
};

auto binarysearch::bs = [&](ll n) {
    ll left=-1, right=n+1;
    while(left + 1 < right){
        ll mid = left + (right - left) / 2;
        if() right = mid;   // good
        else left = mid;    // bad
    }
};

#endif //DEFINE_BINARYSEARCH_HPP