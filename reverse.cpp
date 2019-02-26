// Michael Smith
// October 7th 2018
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void swap(string& str, int i, int j) {
	// Swap the characters int the string.
	char temp = str[j];
	str[j] = str[i];
	str[i] = temp;
}

void reverse(string& str, int i, int j) {
	
	// For loop that iterates through each character swapping the first
	// and last until it reaches the middle.
	for (int x = i, y = j; x < y; x++, y--) {
			swap(str, x, y);
	}
}

int main() {
	
	ifstream file("input.txt");
	while (file.good()) {
		string line;
		int lastspace = 0;
		getline(file, line);
//		if (file.eof()) break;

		// For loop for each word in the line separated by spaces
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ' ') {
				reverse(line, lastspace, i - 1);
				lastspace = i + 1;
			}
		}
		
		// call reverse again for the last word of the line and then print it out
		reverse(line, lastspace, line.length() - 1);
		cout << line << endl;
	}

	system("PAUSE");
}