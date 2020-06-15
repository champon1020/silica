#ifndef INCLUDE_DEBUG_HPP
#define INCLUDE_DEBUG_HPP

#define TO_STRING(varName) # varName
#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace dbg {

using ll = long long;

class Debug {
  void prefix() { cout << "\033[7m\033[35m" << " DEBUG " << "\033[0m" << endl; }

  void out_helper(){ cout << endl; }

  void out_with_name_helper(){ cout << endl; }

  template<typename T1, typename... T2>
  void out_helper(T1 v, T2... args);

  template<typename T1, typename... T2>
  void out_with_name_helper(string s, T1 v, T2... args);

  // value
  template<typename T>
  void print(T val);

  // pair
  template<typename A, typename B>
  void print(pair<A, B> p);

  // tuple
  template<typename A, typename B, typename C>
  void print(tuple<A, B, C> t);

  // vector
  template<typename T>
  void print(vector<T> &vec);

  // set
  template<typename T>
  void print(set<T> &st);

  // map
  template<typename A, typename B>
  void print(map<A, B> mp);
public:
  Debug(){}

  template<typename... T>
  void out(T... args){
    prefix();
    out_helper(args...);
  }

  template<typename... T>
  void out_with_name(T... args){
    prefix();
    out_with_name_helper(args...);
  }

  template<typename T>
  void outg(vector<vector<T>> &g) {
    prefix();
    for(auto& v1 : g){
      for(auto& v2 : v1) {
        cout << v2 << " ";
      }
      cout << endl;
    }
  }
};

template<typename T1, typename... T2>
void Debug::out_helper(T1 v, T2... args) {
  print(v); cout << endl;
  out_helper(args...);
}

template<typename T1, typename... T2>
void Debug::out_with_name_helper(string s, T1 v, T2... args) {
  cout << s << ": "; print(v); cout << endl;
  out_with_name_helper(args...);
}

template<typename T>
void Debug::print(T val){
  cout << val;
}

template<typename A, typename B>
void Debug::print(pair<A, B> p){
  cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")";
}

template<typename A, typename B, typename C>
void Debug::print(tuple<A, B, C> t) {
  cout << "("; print(get<0>(t)); cout << ", "; print(get<1>(t)); cout << ", "; print(get<2>(t)); cout << ")";
}

template<typename T>
void Debug::print(vector<T>& vec) {
  cout << "[";
  bool fir = true;
  for(auto& e : vec) {
    if(!fir) cout << " ";
    print(e), fir=false;
  }
  cout << "]";
}

template<typename T>
void Debug::print(set<T> &st){
  cout << "{";
  bool fir = true;
  for(auto& e : st) {
    if(!fir) cout << " ";
    print(e), fir=false;
  }
  cout << "}";
}

template<typename A, typename B>
void Debug::print(map<A, B> mp){
  cout << "{";
  bool fir = true;
  for(auto& p : mp){
    if(!fir) cout << " ";
    print(p), fir=false;
  }
  cout << "}";
}

}

#endif //INCLUDE_DEBUG_HPP
