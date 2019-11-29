#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


struct Restaurant {
    string name;
    Int p;
    Int id;

    Restaurant(string name_, Int p_, Int id_){
        id = id_;
        name = name_;
        p = p_;
    }

    bool operator<(const Restaurant &another) const {
        if(name == another.name){
            return p > another.p;
        }
        return name < another.name;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, p;
    string s;
    vector<Restaurant> v;
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> s >> p;
        v.push_back(Restaurant(s, p, i+1));
    }
    sort(v.begin(), v.end());
    for(Int i=0; i<n; i++){
        cout << v[i].id << endl;
    }
    return 0;
}