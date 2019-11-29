#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, a, b;
    vector<pair<Int, Int>> pair;
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> a >> b;
        pair.push_back(make_pair(b, a));
    }
    sort(pair.begin(), pair.end());
    Int time = 0;
    for(auto p : pair){
        time += p.second;
        if(time > p.first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}