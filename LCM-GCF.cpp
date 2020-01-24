/*
	Finding the GCD and LCM using the Euclidean algorithm 
*/

#include<iostream>
#include<vector>

// Loop-based gcm algo
int gcd(int a, int b) {
	// assume b is greater than a
	int r = a;
	while(b%a != 0) {
		r = b%a;
		a = r;
		b = a;
	}
	return r;
}

// Recursive gcm algo
int gcdR(int a, int b) {
	if(a == 0) {
		return b;
	} else {
		return gcdR(b%a, a);
	}
	return 0;
}

// Finds the GCD for a sorted array
int gcdForArr(std::vector<int> arr) {
	int ans = 0;
	int a = arr[0];
	for(int i = 1; i < arr.size(); i++) {
		ans = gcdR(a, arr[i]);

		if(ans == 1) {
			return 1;
		}
	}
	return ans;
}

// Finds the LCM for a sorted array
int lcmForArr(std::vector<int> arr) {
	int ans = arr[0];
	for(int i = 1; i < arr.size(); i++) {
		ans = (arr[i] * ans) / gcdR(ans, arr[i]); 
	}
	return ans;
}

// driver code
int main() {
	std::vector<int> arr;
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(8);
	arr.push_back(16);

	// int ans = gcdForArr(arr);
	int ans = lcmForArr(arr);
	
	std::cout << ans << std::endl;
	return 0;
}
