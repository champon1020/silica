#include <iostream>
#include <vector>
#define NIL -1
#define MAX 200000

using namespace std;


struct Node {
    int p;
    vector<int> c;
};

Node t[MAX+1];
int s[MAX+1];

void init(int n){
    for(int i=0; i<=n; i++){
        t[i].p = NIL;
        s[i] = 0;
    }
}

int main(){
    int n, q, a1, a2;
    int buf;
    cin >> n >> q;
    init(n);
    for(int i=1; i<=n-1; i++){
        cin >> a1 >> a2;
        t[a2].p = a1;
        t[a1].c.push_back(a2);
    }
    int p, x;
    for(int i=0; i<q; i++){
        cin >> p >> x;
        s[p] += x;
    }

    for(int i=2; i<=n; i++){
        s[i] += s[t[i].p];
    }

    for(int i=1; i<=n; i++){
        if(i != 1){
            cout << " ";
        }
        cout << s[i];
    }
    cout << endl;
    return 0;
}