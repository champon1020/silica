#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define inf 1e18
using namespace std;

auto bs = [&](ll n) {
    ll left=-1, right=n+1;
    while(left + 1 < right){
        ll mid = left + (right - left) / 2;
        if() right = mid;   // good
        else left = mid;    // bad
    }
};