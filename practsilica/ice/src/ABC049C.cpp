#include <iostream>
#include <string>

using namespace std;

int checkStr(string s);
string getBeginStr(string s, int start, int end);
int it = 0;


string getBeginStr(string s, int start, int end){
    string output = "";
    if(end > s.length()){
        output = "null";
        return output;
    }
    for(int i=start; i<end; i++){
        output += s.at(i);
    }
    return output;
}


int checkStr(string s){
    string buf = getBeginStr(s, it, it+5);
    if(buf == "dream"){
        if(getBeginStr(s, it+5, it+7) == "er" && getBeginStr(s, it+5, it+10) != "erase"){
            it += 7;
            return 1;
        }else{
            it += 5;
            return 1;
        }
    }else if(buf == "erase"){
        if(getBeginStr(s, it+5, it+6) == "r"){
            it += 6;
            return 1;
        }else{
            it += 5;
            return 1;
        }
    }
    return -1;
}


int main(){
    string s, t;
    cin >> s;
    bool result = true;

    while(it < s.length()){
        int r = checkStr(s);
        if(r == -1){
            result = false;
            break;
        }
    }

    if(result){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}