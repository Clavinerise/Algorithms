/*
    Bubblesort
        popular but inefficient sorting algorithm
    Loop invariant: largest int will always be at the rightmost positon. At the end of i iteration, right most i elements are sorted and in place.
    Time complexity:
        best case: O(n)
        average case: O(n^2)
        worse case: O(n^2)
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

void bubblesort(std::vector<int> &arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        for(int j = 0; j < arr.size() - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
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
    arr.push_back(1);
    arr.push_back(2);

    bubblesort(arr);
    std::cout << arr << std::endl;
    return 0;
}