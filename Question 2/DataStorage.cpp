/*
 * DataStorage.cpp
 *
 *  Created on: Apr 11, 2025
 *      Author: jiyongjeon
 */


#include "DataStorage.h"
#include <iostream>
#include <sstream>
using namespace std;

DataStorage::DataStorage(){
	iPtr = nullptr;
	cPtr = nullptr;
	fPtr = nullptr;
}

DataStorage::~DataStorage(){
	delete[] iPtr;
	delete[] cPtr;
	delete[] fPtr;
}

void DataStorage::allocate(const string& type, int size){
	if (type=="int"){
		iPtr = new int[size];
	}
	else if (type == "float"){
		fPtr = new float[size];
	}
	else if (type == "char"){
			cPtr = new char[size];
	}
}

void DataStorage::setData(const string& type, int index, const string& value){
	istringstream iss(value);
	if (type == "int" && iPtr){
		iss >> iPtr[index];
	}
	else if (type == "float" && fPtr) {
		iss >>fPtr[index];
	}
	else if (type == "char"){
		cPtr[index] = value[0];
	}
}

void DataStorage::print(const string& type, int size) const{
	cout << type << " [" << size << "]: ";
	if (type == "int" && iPtr) {
		for (int i = 0; i < size; ++i) cout<<iPtr[i]<<" ";
	}
	else if(type == "float" && fPtr){
		for (int i = 0; i < size; ++i) cout << fPtr[i] << " ";
	}
	else if(type == "char" && cPtr){
		for (int i = 0; i < size; ++i) cout << cPtr[i] << " ";
	}
	cout << endl;
}


