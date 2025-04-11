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

#include "../Question_2/DataStorage.h"
using namespace std;

int main(){
	ifstream infile("config.txt");
	string line;
	int recordCount = 0;

	// First pass: count records
	while (getline(infile, line)) {
		++recordCount;

		//reset file to beginning
		infile.clear();
		infile.seekg(0);

	    // Create dynamic array of DataStorage
	    DataStorage* dsPtr = new DataStorage[recordCount];

	    int recordIndex = 0;

	    while (getline(infile, line)){
	    	istringstream iss(line);
	    	string type;
	    	int size;
	    	iss >> type >> size;

	    	dsPtr[recordIndex].allocate(type, size);

	    	for (int i = 0; i <size; ++i){
	    		string value;
	    		iss >> value;
	    		dsPtr[recordIndex].setData(type, i, value);
	    	}
	    	++recordIndex;
	    }

	    for (int i =0; i<recordCount; ++i){

	        cout << "Record " << i + 1 << ": ";
	        dsPtr[i].print();
	    }

	    delete[] dsPtr;
	    return 0;
	    }
	ifstream isfile("config.txt");
	if (!infile.is_open()) {
	    cout << "Failed to open file!" << endl;
	    return 1;
	}
	}
