/*
 * DataStorage.h
 *
 *  Created on: Apr 9, 2025
 *      Author: benjamin
 */

#ifndef DATASTORAGE_H_
#define DATASTORAGE_H_
#include <string>
using namespace std;

class DataStorage{
private:
	int* iPtr;
	char* cPtr;
	float* fPtr;

public:
	DataStorage();
	~DataStorage();

	void allocate(const string& type, int size);
	void setData(const string& type, int index, const string& value);
	void print(const string& type, int size) const;

};



#endif /* DATASTORAGE_H_ */
