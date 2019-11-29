#include <bits/stdc++.h>
using Int = long long int;
using namespace std;
 
int main(){
  Int n;
  cin >> n;
  Int h[100000];
  for(Int i=0; i<n; i++){
    cin >> h[i];
  }
  bool flg = true;
  for(Int i=0; i<n-1; i++){
    if(i == 0){
      Int r = h[i+1];
      if(r < h[i]-1){
        flg = false;
        break;
      }
      h[i]--;
      continue;
    }
    Int l = h[i-1];
    Int r = h[i+1];
    if(l < h[i]){
      h[i]--;
    }
    if(r < h[i]){
      flg = false;
      break;
    }
  }
  cout << (flg ? "Yes" : "No") << endl;
  return 0;
}