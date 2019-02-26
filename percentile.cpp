// Michael Smith
// CS 361
// October 14th, 2018

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// My quickselect and partition functions are based heavily on the pseudocode found on the quickselect Wiki
// https:///en.wikipedia.org/wiki/Quickselect
int partition(int S[], int left, int right, int pivot) {
	int pivotVal = S[pivot];
	swap(S[pivot], S[right]);
	int storeIndex = left;
	for (int i = left; i < right; i++) {
		if (S[i] < pivotVal) {
			swap(S[storeIndex], S[i]);
			storeIndex++;
		}
	}
	swap(S[right], S[storeIndex]);
	return storeIndex;
}

int quickSelect(int S[], int left, int right, int index) {
	if (left == right)
		return S[left];

	int pivot = left + floor(rand() % (right - left + 1));
	pivot = partition(S, left, right, pivot);

	if (index == pivot) 
		return S[index];
	else if (index < pivot) 
		return quickSelect(S, left, pivot - 1, index);
	else 
		return quickSelect(S, pivot + 1, right, index);
	
}

int percentile(int p, int S[], int size) {
	// Find the index of the percentile by taking the size times the percent and dividing that by 100 then subtracting 1.
	int index = 0;
	index = ceil((size * p) / (double)100) - 1;
	return quickSelect(S, 0, size - 1, index);
}

int main() {

	ifstream file("data.txt");
	string line;
	int size;

	// Get the first line to see how many elements there are
	getline(file, line);

	// Create and put all the elements into an array S with the size we found from the first line
	size = stoi(line);
	int * S = new int[size];
	for (int i = 0; i < size; i++) {
		getline(file, line);
		S[i] = stoi(line);
	}

	// 3 calls of the percentile function for 25, 50, and 75 percentiles.
	cout << percentile(25, S, size) << ' ';
	cout << percentile(50, S, size) << ' ';
	cout << percentile(75, S, size) << endl;

	system("pause");
	return 0;
}