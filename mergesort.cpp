/*
	Mergesort
		Sorts an array of int in O(nlogn) time
	Taken from Introduction to Algorithms by CLRS
*/

#include<iostream>
#include<vector>

std::ostream& operator<< (std::ostream &out, const std::vector<int> &arr) {
	int size = arr.size();
	for(int i = 0; i < size; i++) {
		out << arr[i];
		if(i != size-1) {
			out << ", ";
		}
	}
	return out;
}

void merge(std::vector<int> &arr, int start, int mid, int end) {
	int len1 = mid - start; // length of left array
	int len2 = end - mid; // length of right array

	std::vector<int> left;
	std::vector<int> right;

	int i = 0;
	int j = 0;

	for(i = 0; i <= len1; i++) {
		left.push_back(arr[start+i]);
	}
	// index after mid
	for(j = 1; j <= len2; j++) {
		right.push_back(arr[mid+j]);
	}

	left.push_back(std::numeric_limits<int>::max());
	right.push_back(std::numeric_limits<int>::max());

	i = 0;
	j = 0;
	for(int k = start; k <= end; k++) {
		if(left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
	}

}

void mergesort(std::vector<int> &arr, int start, int end) {
	if(start < end) {
		int mid = (start+end)/2;
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main() {
	std::vector<int> arr;
	arr.push_back(5);
	arr.push_back(1);
	arr.push_back(12);
	arr.push_back(11);
	arr.push_back(3);
	arr.push_back(9);
	arr.push_back(16);
	arr.push_back(4);
	arr.push_back(6);

	mergesort(arr, 0, arr.size()-1);

	std::cout << arr << std::endl;
	return 0;
}
