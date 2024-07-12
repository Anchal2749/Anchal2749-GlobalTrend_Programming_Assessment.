// Given a string, find the length of the longest substring without repeating characters.The function should return an integer representing the length of the longest substring without repeating characters.
#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int lengthofLongestSubstring(string s) {
        vector < int > vec(256, -1); 

 

      int left = 0, right = 0; 

      int n = s.size(); 

      int len = 0; 

      while (right < n) { 

        if (vec[s[right]] != -1) 

          left = max(vec[s[right]] + 1, left); 

 

        vec[s[right]] = right; 

 

        len = max(len, right - left + 1); 

        right++; 

      } 

      return len; 
    }
};

int main() {
  string str = "kranchal";
  Solution obj;
  cout << "Length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}