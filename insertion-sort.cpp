/*
    Insertion sort
    The algorithm sorts the input numbers in place.
    best case: O(n)
    worse case: O(n^2)
*/

#include<iostream>
#include<vector>

// Overload output function to print array
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

// Sorts vector passed in input using the insertion sort
void insertionSort(std::vector<int> &arr) {
    int val = 0;
    int index = 0;
    for(int i = 1; i < arr.size(); i++) {
        val = arr[i];
        index = i;
        for(int j = i-1; j >= 0; j--) {
            if(arr[j] > val) {
                std::swap(arr[j], arr[index]);
                index = j;
            }
        }
    }
}

int main() {
    std::vector<int> arr;
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(16);
    arr.push_back(11);
    arr.push_back(21);
    arr.push_back(2);

    insertionSort(arr);
    std::cout << arr << std::endl;
    return 0;
}