//Write a function to find the greatest common divisor (GCD) of two numbers. The function should return the GCD of a and b.
#include<bits/stdc++.h>
using namespace std;
int getSum(int n)
{
    int d,sum=0;
    while(n!=0)
    {
        d=n%10;
        sum+=d;
        n=n/10;
    }
    return sum;
}
int main()
{
    int n=4782;
    cout<<n<<endl;
    cout<<"Sum of digits of the given number is "<<getSum(n);
    return 0;
}