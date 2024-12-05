#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void popularfriend(string arr[], int count[]) {
	for (int i = 0; arr[i] != ""; i++) {
		for (int j = 0; arr[j] != ""; j++) {
			if (arr[i] == arr[j]) count[i]++;
		}
	}
	int maxIndex = 0;
	for (int i = 1; arr[i] != ""; i++) {
		if (count[i] > count[maxIndex]) maxIndex = i;
	}
	cout << "Popular student = " << arr[maxIndex] << " with " << count[maxIndex] << " friends" << endl;
}

int main() {
	const int maxEntries = 200;
	// const int maxEntries = 200;
	string arr[maxEntries] = {""};
	int count[maxEntries] = {0};
	ifstream file("friends_dataset.csv");
	if (!file.is_open()) return cout << "Error: Could not open the file!" << endl, 1;
	
	string line;
	getline(file, line); // Skip header
	for (int i = 0; getline(file, line) && i < maxEntries; i++) {
		size_t pos = 0;
		while ((pos = line.find(',')) != string::npos) {
			arr[i++] = line.substr(0, pos);
			line.erase(0, pos + 1);
		}
		arr[i] = line; // Last name
	}
	file.close();
	popularfriend(arr, count);
	return 0;
}

