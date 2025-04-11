/*
 * DataStorageDriver.cpp
 *
 *  Created on: Apr 11, 2025
 *      Author: jiyongjeon
 */

#include "DataStorage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	ifstream infile("config.txt");
	string line;
	vector<DataStorage> records;
	vector<string> types;
	vector<int> sizes;

	while (getline(infile, line)) {
		istringstream iss(line);
		string type;
		int size;
		iss >> type >> size;

		DataStorage data;
		data.allocate(type, size);
		types.push_back(type);
		sizes.push_back(size);

		for (int i = 0; i < size; ++i) {
			string value;
			iss >> value;
			data.setData(type, i, value);
		}
		records.push_back(data);
	}

	for (size_t i=0; i < records.size(); ++i) {
		records[i].print(types[i], sizes[i]);
	}
	return 0;

}
