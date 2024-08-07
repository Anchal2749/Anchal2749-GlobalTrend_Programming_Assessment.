//Write a function to rotate an array to the right by k steps.The function should modify the array in place to achieve the rotation.
#include <bits/stdc++.h>
using namespace std;

void rightRotate(int arr[], int n, int d) {

    if (n == 0) return;

    // Get the effective number of rotations:
    d = d % n;

    //reverse last d elements:
    reverse(arr + n - d, arr + n);

    //reverse first (n-d) elements:
    reverse(arr, arr + n - d);

    // reverse whole array:
    reverse(arr, arr + n);
}

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;

    cout << "Before rotation:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    rightRotate(arr, n, d);
    cout << "After rotation:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}