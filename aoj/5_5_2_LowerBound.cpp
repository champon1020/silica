#include <iostream>
#include <algorithm>

using namespace std;


// lower_bound() arguments:
//      1: first (if vector, A.begin()) 
//      2: last  (if vector, A.end())
//      3: value 
//
// this func get first value of more than 3:value.
// In similar, there is upper_bound()

// distance() is func of get distance from A.begin() to pos.
int main(){
    int A[14] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    int *pos;
    int idx;

    pos = lower_bound(A, A+14, 3);
    idx = distance(A, pos);
    cout << "A[" << idx << "] = " << *pos << "\n";

    pos = lower_bound(A, A+14, 2);
    idx = distance(A, pos);
    cout << "A[" << idx << "] = " << *pos << "\n";

    return 0;
}