#include <iostream>

using namespace std;

int main()
{
    int n;
    int array[100];

    cout << "num: ";
    cin >> n;

    cout << "values (open space between each values)";
    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    for(int j=1; j<n; j++){
        int var = array[j];
        int k = j-1;

        while(k>=0 && var>array[k]){
        }
    }


}