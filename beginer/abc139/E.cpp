#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> a;
int now[1000];
int was[1000];

void init(int n){
    for(int i=0; i<n; i++){
        was[i] = 0;
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        vector<int> buf;
        for(int j=0; j<n-1; j++){
            int a_;
            cin >> a_;
            buf.push_back(a_); 
        }
        a.push_back(buf);
        now[i] = 0;
    }

    int cnt = 0;
    int day = 0;
    while(cnt < n*(n-1)/2){
        bool game = false;
        init(n);
        for(int i=0; i<n; i++){
            if(now[i] >= n-1){
                continue;
            }
            int vs = a[i][now[i]]-1;
            if(was[i] == 1){
                continue;
            }
            if(was[vs] == 1){
                continue;
            }
            if(i == a[vs][now[vs]]-1){
                now[i]++;
                now[vs]++;
                game = true;
                cnt++;
                was[i] = 1;
                was[vs] = 1;
            }
        }
        if(!game){
            cout << -1 << endl;
            return 0;
        }
        day++;
    }
    cout << day << endl;
    return 0;
}