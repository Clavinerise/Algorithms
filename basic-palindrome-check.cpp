/*
    Checks if a string is a palindrome
*/

#include<iostream>
#include<string>
#include<algorithm>

// Linear complexity
// based on the length of the string
bool isPalidrome(std::string str) {
    // divide str len by 2
    int len = str.length();
    int half = len/2;

    // compare reversed substring of chars at 0 to half-1 and half (or half+1 if odd) to end
    std::string s1 = str.substr(0, half);
    std::reverse(s1.begin(), s1.begin()+half);
    std::string s2 = len%2 ? str.substr(half+1, len) : str.substr(half, len);

    if(s1==s2) {
        return 1;
    }
    return 0;
}

int main() {
    std::string str = "madam";
    if(isPalidrome(str)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    return 0;
}