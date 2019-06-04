#ifndef CMATRIX_HPP
#define CMATRIX_HPP

#include <ostream>

using namespace std;
/// \class CMatrix CMatrix.hpp
/// \brief Representation of Matrix Entity
/// \author I Putu Gede Darmawan S.Kom (darmawan@bali-electro.com)
template<typename T>
class CMatrix
{
	private:
		T		**m_Matrix;					///< Matrix Element of type T
		int		m_Row;						///< Row Count of CMatrix instance
		int		m_Col;						///< Column Count of CMatrix instance

	protected:

	public:
		/// Constructing Matrix with [row](@ref row) and col size;
		/// \param[in] row Row Number of Matrix
		/// \param[in] col Column Number of Matrix
		CMatrix(const int row,const int col) : m_Row(row),m_Col(col)
		{
			m_Matrix = new T* [m_Row];

			for(int li = 0;li < row;li++)
				m_Matrix[li] = new T[col];

			for(int li = 0;li < row;li++)
				for(int lj = 0;lj < col;lj++)
					this->m_Matrix[li][lj] = (T)0;
		}

		/// A Copy Constructor
		/// \param[in] mat Matrix to be copied
		CMatrix(const CMatrix & mat) : m_Row(mat.m_Row),m_Col(mat.m_Col)
		{

		}

		/// Releasing memory and all desctructing stuff ~CMatrix(); 
		~CMatrix()
		{
			for(int li = 0;li < this->m_Row;li++)
				delete [](m_Matrix[li]);
			delete []m_Matrix;
		}
		
		/// Set Element of Matrix with array of m_row,m_col size
		void setElement(T **item);

		/// Set Element of Matrix at row,col with value
		void setElement(int row,int col,T value)
		{
			this->m_Matrix[row][col] = value;
		}

		/// Set Matrix's Element by row
		/// @param[in] row Matrix's Row Number to bet set
		/// @param[in] ... Element Value. Should be array with m_Col Element
		void setRowLine(int row,...);

		/// Returning Matrix's Element at row,col
		T getElement(int row,int col)
		{
			return this->m_Matrix[row][col];
		}

		//Matrix Multiplication
		CMatrix operator * (CMatrix operand) const;
		CMatrix operator * (int operand) const;

		/// Matrix Addition and SUbstraction
		CMatrix operator + (CMatrix operand) const;
		CMatrix operator - (CMatrix operand) const;

		/// Unary Operator Minus
		CMatrix operator - () const;

		/// Transpose Matrix AxB into BxA
		CMatrix transpose() const;

		/// Return true if m_Row == m_Col 
		bool	isSquare() const;

		/// Friends ostream << operator
		friend ostream & operator << (ostream & os,const CMatrix & mat)
		{
			for(int li = 0;li< mat.m_Row;li++)
			{
				for(int lj = 0;lj < mat.m_Col;lj++)
				{
					os << mat.m_Matrix[li][lj] << ' ';
				}
				os << endl;
			}
			return os;
		}
		
		/// Return a Matrix Identity with dimension x dimension
		static CMatrix getIdentity(int dimension);
		/// Multiply 2 Matrix with size AxB and BxC otherwise throw Exception
		static CMatrix matMul(const CMatrix & matA,const CMatrix & matB);
		/// Multiply a matrix with scalar value
		static CMatrix matMul(const CMatrix & matA,double scalar);
		/// Add 2 Matrix with same dimension
		static CMatrix matAdd(const CMatrix & matA,const CMatrix & matB);
		/// Subtract 2 Matrix with same dimension
		static CMatrix matSub(const CMatrix & matA,const CMatrix & matB);
		/// Multiplay Matrix with -1
		static CMatrix matMinus(const CMatrix & mat);
		/// return true if matrix mat has m_Row == m_Col
		static bool isSquare(const CMatrix & mat);
};

/*
template <typename T>
ostream & operator << (ostream & os,const CMatrix<T> & mat)
{
}
*/

#endif
