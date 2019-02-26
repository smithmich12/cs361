// Michael Smith
// CS 361
// September 30, 2018
#include <iostream>
using namespace std;

void permutations(bool nArray[], int s, int k, int size, int results[]) {
	// base case
	if (k == 0) {
		// Print out the results everytime we hit the bottom
		for (int i = s - 1; i >= 0; i--) {
			cout << results[i];
		}
		cout << ' ';
		return;
	}

	for (int i = 0; i < size; i++) {
		if (nArray[i] == false) {
			nArray[i] = true;
			results[k - 1] = i;
			permutations(nArray, s, k - 1, size, results);
			nArray[i] = false;
		}
	}

	return;
}

int main(int argc, char* argv[]) {
	// Variables for n and k. n
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);

	// Boolean array to track where we have been and an int array to print out the results
	bool * nArray = new bool [n];
	int * results = new int[k];

	// set all values in the nArray to false
	for (int i = 0; i < n; i++) {
		nArray[i] = false;
	}

	// set all values in the results to 0
	for (int i = 0; i < k; i++) {
		results[i] = 0;
	}

	// call permutations
	permutations(nArray, k, k, n, results);

	cout << endl;
	system("PAUSE");
	return 0;
}
