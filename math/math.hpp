#ifndef DEFINE_MATH_HPP
#define DEFINE_MATH_HPP

#include <vector>
#include <map>
using namespace std;

namespace math {

using ll = long long;

class Math {
    ll mod;
public:
  Math(ll mod = 1e9+7):mod(mod){}
  ll keta(ll num);
  ll gcd(ll a, ll b);
  ll lcm(ll a, ll b);
  ll powm(ll num1, ll num2);
  bool isPrime(ll n);

  // 素因数分解(pair vector)
  template<typename T> vector<pair<ll, ll>> factor(T n);

  // 約数(vector)
  template<typename T> vector<ll> divisor(T n);
  // オイラー関数
  template<typename T> ll euler(T n);

  // b進数に変換
  vector<ll> changeBase(ll n, int b);
};

ll Math::keta(ll num) {
  ll k = 0;
  while (num > 0) {
    num /= 10;
    k++;
  }
  return k;
}

ll Math::gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll Math::lcm(ll a, ll b) {
  return a * (b / gcd(a, b));
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

bool Math::isPrime(ll n) {
  bool flg = true;
  for(ll i=2; i*i<=n; i++){
      if(n%i == 0) {
          flg = false;
          break;
      }
  }
  return flg;
}

template<typename T>
vector<pair<ll, ll>> Math::factor(T n){
  vector<pair<ll, ll>> res;
  for(ll i=2; i*i<=n; i++){
    if(n%i != 0) continue;
    int cnt = 0;
    while(n%i == 0){
      ++cnt;
      n /= i;
    }
    res.emplace_back(i, cnt);
  }
  if(n > 1) res.emplace_back(n, 1);
  return res;
}

template<typename T>
vector<ll> Math::divisor(T n){
  vector<ll> res;
  for(ll i=1; i*i<=n; i++){
    if(n%i == 0){
      if(i*i == n) res.push_back(i);
      else{
        res.push_back(i);
        res.push_back(n/i);
      }
    }
  }
  return res;
}

template<typename T>
ll Math::euler(T n) {
  ll res = n;
  auto pv = factor(n);
  for(auto& p : pv){
    res *= (p.first-1);
    res /= p.first;
  }
  return res;
}

vector<ll> Math::changeBase(ll n, int b){
  vector<ll> v;
  while(n > 0){
    ll r = n%b;
    if(r == 0) --n;
    n /= n;
    v.push_back((r-1+b)%b);
  }
  return v;
}

}

#endif //DEFINE_MATH_HPP
