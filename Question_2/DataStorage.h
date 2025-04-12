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
    string type;
    int size;

public:
	DataStorage();
	~DataStorage();

	void allocate(const string& type, int size);
	void setData(int index, const string& value);
	void print() const;

};



#endif /* DATASTORAGE_H_ */
