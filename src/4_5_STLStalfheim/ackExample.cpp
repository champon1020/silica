#include <iostream>
#include <stack>

using namespace std;


int main(){
    stack<int> S;

    S.push(3);
    S.push(7);
    S.push(1);

    cout << S.size() << "\n";

    cout << S.top() << "\n";
    S.pop();

    cout << S.top() << "\n";
    S.pop();

    cout << S.top() << "\n";

    S.push(5);

    cout << S.top() << "\n";
    S.pop();

    cout << S.top() << "\n";

    return 0;
}