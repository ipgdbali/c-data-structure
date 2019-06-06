#include <iostream>
#include "header/CMatrix.hpp"

using namespace std;

int main(int argc,char *argv[])
{
	CMatrix<double> MatrixA(4,4);
	CMatrix<double> MatrixB(4,1);

	for(int li = 0;li < MatrixA.getWidth();li++)
		MatrixA.setElement(li,li,li + 1);

	for(int li = 0;li < MatrixB.getHeight();li++)
		MatrixB.setElement(li,0,1.0);

	cout << MatrixA << endl;
	cout << MatrixB << endl;
    cout << MatrixA * MatrixB << endl;
	cout << MatrixA.getSize() << endl;

	return 0;
}
