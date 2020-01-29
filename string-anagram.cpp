#include<iostream>
#include<string>
#include<vector>

// Sorting and Check
// approximately O(N*logN) for the sorting
bool anagramCheck(std::string str1, std::string str2) {

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    if(str1==str2) {
        return 1;
    }
    return 0;
}

// Character count array
// assume limit set of characters
// O(n) -> based on length of string
bool anagramCheckWithCountArr(std::string str1, std::string str2, int possibleChars) {
    // check length
    int len = str1.length();
    if(len != str2.length()) {
        return 0;
    }

    std::vector<int> count(possibleChars, 0);
    for(int i = 0; i < len; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }
    for(int i = 0; i < possibleChars; i++) {
        if(count[i]!=0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    int possibleChars = 256;
    std::string str1 = "porcupine";
    std::string str2 = "ippurceon";

    if(anagramCheck(str1, str2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    if(anagramCheckWithCountArr(str1, str2, possibleChars)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}