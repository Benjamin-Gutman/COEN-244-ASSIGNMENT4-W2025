//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#ifndef DATASTORAGE_H_
#define DATASTORAGE_H_
#include <string>
using namespace std;

class DataStorage{
private:
    int* iPtr;         // Pointer for storing int array (used if type is "int")
    char* cPtr;        // Pointer for storing char array (used if type is "char")
    float* fPtr;       // Pointer for storing float array (used if type is "float")

    string type;       // Type of data ("int", "float", or "char")
    int size;          // Number of elements in the allocated array

public:
    DataStorage();                      // Constructor to initialize pointers
    ~DataStorage();                     // Destructor to deallocate memory

    void allocate(const string& type, int size); // Allocates appropriate array based on type
    void setData(int index, const string& value); // Sets data at a specific index
    void print() const;                         // Prints the stored array

};



#endif /* DATASTORAGE_H_ */
