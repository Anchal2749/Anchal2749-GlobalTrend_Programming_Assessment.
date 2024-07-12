//Write a function to check if a given string contains only alphabetic characters.The function should return true if the string contains only alphabetic characters, and false otherwise.
#include <iostream>
#include <string>
#include <cctype>

bool isAlphabetic(const std::string& str) {
    for (char ch : str) {
        if (!std::isalpha(static_cast<unsigned char>(ch))) {
            return false;
        }
    }
    return true;
}

int main() {
   
    std::string test = "Hello123";
    std::cout << std::boolalpha; // To print bools as true/false

    std::cout << test <<" \n"<< isAlphabetic(test) << std::endl; // Should print false
    
    return 0;
}


    
                                
                            
                     
                        