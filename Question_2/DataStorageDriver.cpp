/*
 * DataStorageDriver.cpp
 *
 *  Created on: Apr 11, 2025
 *      Author: jiyongjeon
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <unistd.h>								/////////

#include "../Question_2/DataStorage.h"
using namespace std;

int main(){

	char path[1024];                          	 //this code i got it from chatgpt because i didn't know where the program is targetting for txt file.
	getcwd(path, sizeof(path));					////////
	cout << "Working dir: " << path << endl;	///////

	ifstream inFile;
	inFile.open("config.txt", ios::in);
	// checks if file is opened properly
	if ( !inFile ) {
	cerr << "File could not be opened" << endl;
	exit(EXIT_FAILURE);
	}

	string line;
	int recordCount = 0;

    // First pass to count how many records
    while (getline(inFile, line)) {
        ++recordCount;
    }

    // Reset file
    inFile.clear();
    inFile.seekg(0, ios::beg);

    // Allocate array after knowing the number of records
    DataStorage* records = new DataStorage[recordCount];

    int i = 0;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string type;
        int size;
        ss >> type >> size;

        records[i].allocate(type, size);

        for (int j = 0; j < size; ++j) {
            string val;
            ss >> val;
            records[i].setData(j, val);
        }

        ++i;
    }

    inFile.close();

    // Print output
    for (int i = 0; i < recordCount; ++i) {
        cout << "Record " << i + 1 << ": ";
        records[i].print();
    }

    delete[] records;
    return 0;
}
