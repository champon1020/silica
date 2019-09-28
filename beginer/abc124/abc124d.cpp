#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, k;
    char s[1000001];
    cin >> n >> k;
    cin >> s;

    vector<Int> v;
    Int i=0;
    Int cnt=0;
    char marker = s[0];
    while(i<n){
        if(s[i]==marker){
            cnt++;
        }else{
            v.push_back(cnt);
            marker=s[i];
            cnt=1;
        }
        i++;
    }
    if(cnt!=0){
        v.push_back(cnt);
    }

    Int max=0;
    if(s[0]=='1'){
        for(Int i=0; i<n-2*k-1; i+=2){
            Int sum=0;
            for(Int j=i; j<i+2*k+1; j++){
                sum += v[j];
            }
            max = sum > max ? sum : max;
        }
    }
    cout << max << endl;

    return 0;
}