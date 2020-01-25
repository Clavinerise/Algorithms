/*
	Permutation of elements in an array using Heap's algorithm.
	Permutation = order matters
*/

#include<iostream>
#include<string>
#include<vector>

// Overload output function to print array
std::ostream& operator<< (std::ostream &out, const std::vector<std::string> &arr) {
	int size = arr.size();
	for(int i = 0; i < size; i++) {
		out << arr[i];
		if(i != size-1) {
			out << ", ";
		}
	}
	return out;
}

// Heap's algorithm
// From Wikipedia: it was proposed by B. R. Heap in 1963
// Not related to Heapsort or heap data structure
void perm(std::vector<std::string> &arr, int size) {
	int i;
	if(size == 1) {
		// print this arr
		std::cout << arr << std::endl;
	} else {
		// generate permutations with the [size-1] element (zero-index) unaltered
		perm(arr, size-1);
		for(i = 0; i < size-1; i++) {

			if(size%2 == 0) {
				// if even, swap element at i with last element
				std::swap(arr[i], arr[size-1]);
			} else {
				// if odd, swap first element with last element
				std::swap(arr[0], arr[size-1]);
			}
			perm(arr, size-1);
		}
	}
}

int main() {
	std::vector<std::string> arr;
	arr.push_back("A");
	arr.push_back("B");
	arr.push_back("C");
	arr.push_back("D");

	int size = arr.size();
	perm(arr, size);
	return 0;
}
