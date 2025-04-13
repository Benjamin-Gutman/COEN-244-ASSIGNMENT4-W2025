//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#ifndef QUESTION_1_2DMATRIX_H_
#define QUESTION_1_2DMATRIX_H_


class Matrix{

private:
	//Using a single dimension array and an indexing algorithm
	int rows;
	int columns;
	int* elements;

public:
	//Class constructors
	Matrix(int, int);
	Matrix(Matrix&);

	//destructor
	~Matrix();

	//element initializer
	void setElement(int, int, int);

	//operator overloading

	// () used for finding the items in the array instead of using [][]
	int operator()(int, int);
	Matrix& operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	bool operator==(const Matrix&);
	bool operator!=(const Matrix&);

};


#endif /* QUESTION_1_2DMATRIX_H_ */
