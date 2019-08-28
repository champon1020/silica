#include <iostream>
#define NIL -1
#define MAX 200000

using namespace std;

struct Node {
    int p, l, r;
};

Node t[MAX];
int s[MAX];

void init(int n){
    for(int i=0; i<=n; i++){
        t[i].p = t[i].l = t[i].r = NIL;
        s[i] = 0;
    }
}

void print(int i){
    cout << i << " " << t[i].l << " " << t[i].r << " " << t[i].p << endl;
}

void rec(int u, int x){
    s[u] += x;
    if(t[u].l != NIL){
        rec(t[u].l, x);
    }
    if(t[u].r != NIL){
        rec(t[u].r, x);
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
        if(t[a1].l == NIL){
            t[a1].l = a2;
        }else{
            t[buf].r = a2;
        }
        buf = a2;
    }
    int p, x;
    for(int i=0; i<q; i++){
        cin >> p >> x;
        s[p] += x;
        if(t[p].l != NIL){
            rec(t[p].l, x);
        }
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