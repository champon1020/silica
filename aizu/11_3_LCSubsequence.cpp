#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

int c[MAX][MAX];

int lcs(string x, string y){
    int xl = x.length();
    int yl = y.length();
    int maxl = 0;
    x = ' '+x;
    y = ' '+y;
    for(int i=0; i<=xl; i++){
        c[i][0] = 0;
    }
    for(int i=0; i<=yl; i++){
        c[0][i] = 0;
    }
    for(int i=1; i<=xl; i++){
        for(int j=1; j<=yl; j++){
            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1] + 1;
            }else{
                c[i][j] = (c[i-1][j] > c[i][j-1]) ? c[i-1][j] : c[i][j-1];
            }
            maxl = (maxl > c[i][j]) ? maxl : c[i][j];
        }
    }
    return maxl;
}

int main(){
    int n;
    string s1, s2;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}