#include <iostream>

using namespace std;


string getStr(string s, int start, int end){
    string output = "";
    for(int i=start; i<end; i++){
        output += s.at(i);
    }
    return output;
}


int getSum(string s, int n){
    
}


int main(){
    string s;
    cin >> s;
    int len = s.length();
    int sum = 0;
    
    int cnt = 0;
    while(cnt <= len-1){
        for(int i=0; i<cnt+1; i++){
            
        }
        cnt++;
    }
    cout << sum << endl;
    return 0;
}