//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#include <iostream>
#include <string>

#include "../Question_1/2DMatrix.h"
using namespace std;

int main(){
	try{

		//initialize the matrices
	Matrix matrix1(2,2);
	Matrix matrix2(2,2);
	Matrix matrix3(3,2);
	Matrix matrix4(2,2);


	matrix1.setElement(0,0,1);
	matrix1.setElement(0,1,2);
	matrix1.setElement(1,0,3);
	matrix1.setElement(1,1,4);

	matrix2.setElement(0,0,1);
	matrix2.setElement(0,1,2);
	matrix2.setElement(1,0,3);
	matrix2.setElement(1,1,4);


	matrix3.setElement(0,0,1);
	matrix3.setElement(0,1,1);
	matrix3.setElement(1,0,1);
	matrix3.setElement(1,1,1);
	matrix3.setElement(2,0,1);
	matrix3.setElement(2,1,1);
	matrix3.setElement(2,0,1);
	matrix3.setElement(2,1,1);

	matrix4.setElement(0,0,2);
	matrix4.setElement(0,1,4);
	matrix4.setElement(1,0,6);
	matrix4.setElement(1,1,8);



	//Test function for finiding items at a location
	int matrixValue = matrix1(1,1);

	if(matrixValue == 4){
		cout << "Indexing Test Passed" << endl;
	}
	else{
		cout << "Indexing Test Failed"<< endl;
	}


	if (matrix1 == matrix2){
		cout << "Equality Test 1 Passed"<< endl;
	}
	else{
		cout << "Equality Test 1 Failed"<< endl;
	}


	//testing addition, equality and inequality
	matrix1 = matrix1+matrix2;

	if (matrix4 == matrix1){
		cout << "Addition Test Passed"<< endl;
	}
	else {
		cout << "Addition Test Failed"<< endl;
	}

	if (matrix1 == matrix3){
		cout << "Equality Test 2 Failed"<< endl;
	}
	else {
		cout << "Equality Test 2 Passed"<< endl;
	}


	if (matrix4 != matrix1){
		cout << "Inequality Test Failed"<< endl;
	}
	else {
		cout << "Inequality Test Passed"<< endl;
	}

	if (matrix1 != matrix3){
		cout << "Inequality Test 2 Passed"<< endl;
	}
	else {
		cout << "Inequality Test 2 Failed"<< endl;
	}

	if (matrix1 != matrix2){
		cout << "Inequality Test 3 Passed"<< endl;
	}
	else {
		cout << "Inequality Test 3 Failed"<< endl;
	}



	//testing subtraction
	matrix1 = matrix1-matrix2;

	if (matrix2 == matrix1){
			cout << "Subtraction Test Passed"<< endl;
		}
		else {
			cout << "Subtraction Test Failed"<< endl;
		}


	//testing exception handling
	matrix4 = matrix1+matrix3;


	}
	catch(string str){
		cout << str << endl;
	}

	return 0;
}
