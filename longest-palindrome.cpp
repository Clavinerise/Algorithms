#include<iostream>
#include<string>

std::string longestPalindrome(std::string str) {
    std::string longest = "";
    
    // base case: empty string -> returns empty
    // trivial case: single char -> returns string
    
    int len = str.length();
    if(len < 2) {
        return str;
    }

    // 
    
    return longest;
}

int main() {
    std::string str = "heamadamder"; // madam
    std::cout << longestPalindrome(str) << std::endl;
    return 0;
}