#include "header/CMatrix.hpp"
#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
	CMatrix<double> matA(2,2);
	matA.setElement(0,0,5.0);
	matA.setElement(1,1,10.0);
	cout << matA;
	return 0;
}
