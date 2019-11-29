#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long cnt = 0;
    string tmp;
    vector<char> s;
    map<string, int> m;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        for(int j=0; j<10; j++){
            s.push_back(tmp.at(j));
        }
        sort(s.begin(), s.end());
        string buf = "";
        for(int i=0; i<10; i++){
            buf += s[i];
        }
        if(m.find(buf) == m.end()){
            m.insert(make_pair(buf, 0));
        }else{
            cnt += m.at(buf)+1;
            m.at(buf)++;
        }
        s.clear();
    }
    cout << cnt << endl;

    return 0;
}