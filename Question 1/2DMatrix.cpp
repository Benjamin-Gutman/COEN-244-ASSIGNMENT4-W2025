/*
 * 2DMatrix.cpp
 *
 *  Created on: Apr 8, 2025
 *      Author: benjamin
 */


#include <iostream>
#include "2DMatrix.h"

Matrix :: Matrix(int row, int column){
	rows = row;
	columns = column;
	elements = new int[row*column];
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
	rows = assign.rows;
	columns = assign.columns;

	for (int i = 0; i < (rows*columns); i++){

	}
}
