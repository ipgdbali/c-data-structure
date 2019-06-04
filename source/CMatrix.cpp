#include "CMatrix.hpp"
#include <cstdlib>

using namespace std;

template <typename T>
CMatrix<T>::CMatrix(int row,int col)
{
	this->m_Row = row;
	this->m_Col = col;

	m_Matrix = (T**)malloc(sizeof(T*) * row);

	for(int li = 0;li < row;li++)
		m_Matrix[li] = malloc(sizeof(T) * col);
}

template <typename T>
CMatrix<T>::~CMatrix()
{
	for(int li = 0;li < this->m_Row;li++)
	{
		free(m_Matrix[li]);
		m_Matrix[li] = 0;
	}
	free(m_Matrix);
	m_Matrix = 0;
}

template <typename T>
bool CMatrix<T>::isSquare() const
{
	return (this->m_Row == this->m_Col);
}

template <typename T>
CMatrix<T> getIndentity(int dimension)
{
	CMatrix matrix(dimension,dimension);
}
