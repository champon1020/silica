#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


Int min(Int a, Int b){
    return a < b ? a : b;    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, k;
    vector<Int> v;
    cin >> n >> k;
    for(Int i=0; i<n; i++){
        cin >> tmpi;
        v.push_back(tmpi);
    }

    Int max = 0;
    for(Int l=0; l<=min(n, k); l++){
        for(Int r=0; r<=min(n, k)-l; r++){
            vector<Int> hand;
            Int sum = 0;

            for(Int i=0; i<l; i++){
                hand.push_back(v[i]);
                sum += v[i];
            }
            for(Int i=0; i<r; i++){
                hand.push_back(v[n-1-i]);
                sum += v[n-1-i];
            }

            sort(hand.begin(), hand.end());
            for(Int i=0; i<k-r-l; i++){
                if(hand.empty()){
                    break;
                }
                Int& f = hand.front();
                if(f < 0){
                    sum -= f;
                    hand.erase(hand.begin());
                }else{
                    break;
                }
            }

            // cout << sum << ": ";
            // for(Int i=0; i<hand.size(); i++){
            //     cout << hand[i] << " ";
            // }
            // cout << endl;
            
            max = sum > max ? sum : max;
        }
    }

    cout << max << endl;

    return 0;
}