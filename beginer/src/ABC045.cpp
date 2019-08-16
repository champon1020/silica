#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


string getStr(string str, int start, int end){
    string out = "";
    for(int i=start; i<end; i++){
        out += str.at(i);
    }
    return out;
}


int main(){
    string s;
    cin >> s;
    int n = s.length();

    long sum = 0;
    for(int bit = 0; bit < (1<<(n-1)); bit++){
        int bufi = 0;
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                string buf = getStr(s, bufi, i+1);
                sum += atol(buf.c_str());
                bufi = i+1;
            }
        }
        sum += atol(getStr(s, bufi, n).c_str());
    }

    cout << sum << endl;
    return 0;
}