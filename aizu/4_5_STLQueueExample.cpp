#include <iostream>
#include <queue>
#include <string>

using namespace std;


int main(){
    queue<string> Q;

    Q.push("red");
    Q.push("yellow");
    Q.push("yellow");
    Q.push("blue");

    cout << Q.front() << "\n";
    Q.pop();

    cout << Q.front() << "\n";
    Q.pop();

    cout << Q.front() << "\n";
    Q.pop();

    Q.push("green");

    cout << Q.front() << "\n";
    Q.pop();

    cout << Q.front() << "\n";

    return 0;
}