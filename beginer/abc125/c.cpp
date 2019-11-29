#include <iostream>
#include <vector>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


Int gcd(Int a, Int b){
    Int p, q, r, s;
    p = a > b ? a : b;
    q = a > b ? b : a;
    while(true){
        //cout << p << " " << q << " " << s << " " << r << endl;
        s = p/q;
        r = p%q;
        if(r==0){
            break;
        }else{
            p = q;
            q = r;
        }
    }
    return q;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, tmpi;
    vector<Int> a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmpi;
        a.push_back(tmpi);
    }

    Int l[100001], r[100001];
    l[0] = a[0];
    r[n-1] = a[n-1];

    for(int i=1; i<n-1; i++){
        l[i] = gcd(l[i-1], a[i]);
    }
    for(Int i=n-2; i>=1; i--){
        r[i] = gcd(r[i+1], a[i]);
    }
    Int max = 0;
    for(int i=0; i<n; i++){
        Int m = 0;
        if(i==0){
            m = r[1];
        }else if(i==n-1){
            m = l[n-2];
        }else{
            m = gcd(l[i-1], r[i+1]);
        }
        max = m > max ? m : max;
    }

    cout << max << endl;
    return 0;
}