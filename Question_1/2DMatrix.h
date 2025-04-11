/*
 * 2DMatrix.h
 *
 *  Created on: Apr 8, 2025
 *      Author: benjamin
 */

#ifndef QUESTION_1_2DMATRIX_H_
#define QUESTION_1_2DMATRIX_H_


class Matrix{

private:
	int rows;
	int columns;
	int* elements;

public:
	Matrix(int, int);
	Matrix(Matrix&);
	~Matrix();

	void setElement(int, int, int);

	int operator()(int, int);
	Matrix& operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	bool operator==(const Matrix&);
	bool operator!=(const Matrix&);

};


#endif /* QUESTION_1_2DMATRIX_H_ */
