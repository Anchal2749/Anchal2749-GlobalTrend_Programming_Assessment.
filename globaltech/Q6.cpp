//Write a function to find the factorial of a given number.The function should return the factorial of the number.
#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
   // Base Case.
   if(n == 0)
   {
       return 1;
   }
   return n * factorial(n-1);
}

int main(){
  
  // Here, let’s take the value of n to be 3.
  int n = 5;
  cout<<"input: "<<n<<endl;
  cout<<factorial(n)<<endl;
  return 0;

}