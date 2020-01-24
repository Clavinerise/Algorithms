#include<iostream>

// a^b
int exp(int a, int b) {
    if(b==0) {
        return 1;
    } else if(b==1) {
        return a;
    } else if(b%2==0) {
        return exp(a*a, b/2);
    } else if(b%2==1) {
        return a*exp(a*a, ((b-1)/2));
    }
    return 0;
}

int main() {
    std::cout << exp(2, 16) << std::endl;
    std::cout << exp(3, 15) << std::endl;
    return 0;
}