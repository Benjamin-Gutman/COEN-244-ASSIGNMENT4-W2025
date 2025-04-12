/*
 * DataStorage.cpp
 *
 *  Created on: Apr 11, 2025
 *      Author: jiyongjeon
 */


#include "../Question_2/DataStorage.h"

#include <iostream>
#include <sstream>
using namespace std;


// Constructor initializes all pointers and variables
DataStorage::DataStorage(){
	iPtr = nullptr;
	cPtr = nullptr;
	fPtr = nullptr;
	type = "";
	size = 0;
}

// Destructor safely deallocates whichever pointer was used
DataStorage::~DataStorage(){
	delete[] iPtr;
	delete[] cPtr;
	delete[] fPtr;
}

// Allocates dynamic memory for the selected type, resets other pointers
void DataStorage::allocate(const string& type, int size) {
    this->type = type;
    this->size = size;

    if (type == "int") {
        iPtr = new int[size];
        fPtr = nullptr;
        cPtr = nullptr;
    } else if (type == "float") {
        fPtr = new float[size];
        iPtr = nullptr;
        cPtr = nullptr;
    } else if (type == "char") {
        cPtr = new char[size];
        iPtr = nullptr;
        fPtr = nullptr;
    }
}

// Parses the string and stores it into the appropriate array
void DataStorage::setData(int index, const string& value) {
    istringstream iss(value);
    if (type == "int" && iPtr) {
        iss >> iPtr[index];
    } else if (type == "float" && fPtr) {
        iss >> fPtr[index];
    } else if (type == "char" && cPtr) {
        cPtr[index] = value[0];
    }
}

// Prints the data in [type: value1 value2 ...] format
void DataStorage::print() const {
    cout << type << " [" << size << "]: ";
    if (type == "int" && iPtr) {
        for (int i = 0; i < size; ++i)
            cout << iPtr[i] << " ";
    } else if (type == "float" && fPtr) {
        for (int i = 0; i < size; ++i)
            cout << fPtr[i] << " ";
    } else if (type == "char" && cPtr) {
        for (int i = 0; i < size; ++i)
            cout << cPtr[i] << " ";
    }
    cout << endl;
}

