/*
    Uses backtracking to generate permutation

    From https://medium.com/algorithms-and-leetcode/backtracking-e001561b9f28
    "Backtracking incrementatlly builds candidates to the solutions... 
    Backtracking is all about choices and consequences, this is why 
    backtracking is the most common algorithm for solving constraint 
    satisfaction problems."

    Properties

    1. No repetition and completition: systematic generating method that avoids repetitions and missing any possible right solution

    2. Search pruning: allows for early exit when solution is 
    worse than known possible solution or acceptable complete
    solution will not be met in current branch
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

void permute(std::vector<std::string> &arr, int start, int end) {
    if(start==end) {
        std::cout << arr << std::endl;
    } else {
        for(int i = start; i <= end; i++) {
            // swap iteratively
            std::swap(arr[start], arr[i]);
            permute(arr, start+1, end);
            // swap back to previous node
            std::swap(arr[start], arr[i]);
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
	permute(arr, 0, size-1);
    return 0;
}