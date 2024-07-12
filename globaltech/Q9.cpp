//Write a function to find the maximum difference between any two elements in an array.The function should return the maximum difference between any two elements in the array.
#include <iostream>
#include <algorithm>

using namespace std;

int findGcd(int a, int b) {
   
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b;
        }
        else {
            b = b % a; 
        }
    }
    if(a == 0) {
        return b;
    }
    return a;
}

int main() {
    int n1 = 20, n2 = 34;
    
    // Find the GCD of n1 and n2
    int gcd = findGcd(n1, n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

    return 0;
}