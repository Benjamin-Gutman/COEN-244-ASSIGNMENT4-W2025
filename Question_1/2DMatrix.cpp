//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#include "../Question_1/2DMatrix.h"

#include <iostream>
#include <string>
using namespace std;



//Class constructors
Matrix :: Matrix(int row, int column){
	rows = row;
	columns = column;
	elements = new int[row*column];
}

Matrix:: Matrix(const Matrix& copy){
	rows = copy.rows;
	columns = copy.columns;
	elements = new int[rows*columns];
	for (int i = 0; i < rows*columns; i++){
		elements[i] = copy.elements[i];
	}
}

//destructor
Matrix :: ~Matrix(){
	delete[] elements;
	cout << "Matrix Deleted" << endl;
}


//Takes the positions as an input
void Matrix::setElement(int i, int j, int num){
	int position = (i*columns) +j;
	elements[position] = num;
}


//finds the item at a specific location and prints it out
int Matrix::operator()(int i, int j) const{
	int position = (i*columns) +j;
	if (position >= columns*rows){
		throw string("Error: Out Of Range");
	}
	return elements[position];
}


//assigns one matrix to another if the dimensions are the same
Matrix& Matrix:: operator=(const Matrix& assign){
	if(rows != assign.rows || columns != assign.columns){
		throw "Error: Different Sized Arrays";

	}
	else if (&assign != this){
		for (int i = 0; i < (rows*columns); i++){
			elements[i] = assign.elements[i];
		}
	}
	return *this;
}


//adds two matrices of the same size together
Matrix Matrix:: operator+(const Matrix& right){
	Matrix result(*this);

	if (rows == right.rows && columns == right.columns){
		for (int i = 0; i < (rows*columns); i++){
				 result.elements[i]= elements[i] + right.elements[i];
			}
	}
	else{
		throw string("Error: Different Sized Arrays");
	}
	return result;
}


//subtracts two matrices of the same size
Matrix Matrix:: operator-(const Matrix& right){
	Matrix result(*this);
	if (rows == right.rows && columns == right.columns){
		for (int i = 0; i < (rows*columns); i++){
				 result.elements[i]= elements[i] - right.elements[i];
			}
	}
	else {
		throw string("Error: Different Sized Arrays");
	}
	return result;
}

//equality verifier
bool Matrix:: operator==(const Matrix& right){
	if (rows == right.rows && columns == right.columns){
		for (int i = 0; i < (rows*columns); i++){
				if (elements[i] != right.elements[i]){
					return false;
				}
			}
		return true;
	}
	return false;

}

//inequality verifier
bool Matrix:: operator!=(const Matrix& right){
	if (rows == right.rows && columns == right.columns){
		for (int i = 0; i < (rows*columns); i++){
				if (elements[i] != right.elements[i]){
					return true;
				}
			}
		return false;
	}
	return true;

}









