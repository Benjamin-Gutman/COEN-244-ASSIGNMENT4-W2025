/*
 * 2DMatrix.cpp
 *
 *  Created on: Apr 8, 2025
 *      Author: benjamin
 */


#include <iostream>
#include "2DMatrix.h"
using namespace std;

Matrix :: Matrix(int row, int column){
	rows = row;
	columns = column;
	elements = new int[row*column];
}

Matrix:: Matrix(Matrix& copy){
	rows = copy.rows;
	columns = copy.columns;
	elements = new int[rows*columns];
	for (int i = 0; i < rows*columns; i++){
		elements[i] = copy.elements[i];
	}
}

Matrix :: ~Matrix(){
	delete[] elements;
	cout << "Matrix Deleted" << endl;
}

void Matrix::setElement(int i, int j, int num){
	int position = (i*columns) +j;
	elements[position] = num;
}


int Matrix::operator()(int i, int j){
	int position = (i*columns) +j;
	return elements[position];
}

const Matrix& Matrix:: operator=(const Matrix& assign){
	if (&assign != this){
		rows = assign.rows;
		columns = assign.columns;

		for (int i = 0; i < (rows*columns); i++){
			elements[i] = assign.elements[i];
		}
	}
	return *this;
}


const Matrix& Matrix:: operator+(const Matrix& right){
	Matrix result(*this);
	if (rows == right.rows && columns == right.columns){
		for (int i = 0; i < (rows*columns); i++){
				 result.elements[i]= elements[i] + right.elements[i];
			}
	}
	return result;
}



const Matrix& Matrix:: operator-(const Matrix& right){
	Matrix result(*this);
	if (rows == right.rows && columns == right.columns){
		for (int i = 0; i < (rows*columns); i++){
				 result.elements[i]= elements[i] - right.elements[i];
			}
	}
	return result;
}


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









