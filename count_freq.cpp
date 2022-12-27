 #include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
    int n = sizeof(arr) / sizeof(int);
    //Search in a sorted array
    int key ;
    cin >> key;

   

    cout<< upper_bound(arr, arr + n, key) - lower_bound(arr, arr + n,key) <<endl;

    return 0;
}