#include "CMatrix.hpp"

using namespace std;

template <typename T>
CMatrix<T>::CMatrix(const int row,const int col)
{
}


template <typename T>
CMatrix<T>::CMatrix(const CMatrix & mat) : CMatrix(mat.m_Row,mat.m_Col)
{
	/// Copy Value
	for(int li = 0; li < mat.m_Row;li++)
		for(int lj = 0;lj < mat.m_Col;lj++)
			this->m_Matrix[li][lj] = mat.m_Matrix[li][lj];
}

template <typename T>
CMatrix<T>::~CMatrix()
{
	for(int li = 0;li < this->m_Row;li++)
		delete [](m_Matrix[li]);
	delete []m_Matrix;
}

template <typename T>
bool CMatrix<T>::isSquare() const
{
	return (this->m_Row == this->m_Col);
}

template <typename T>
CMatrix<T> getIndentity(int dimension)
{
	CMatrix<T> matrix(dimension,dimension);
	for(int li = 0;li<dimension;li++)
		matrix.m_Matrix[li][li] = (T)1;
}
