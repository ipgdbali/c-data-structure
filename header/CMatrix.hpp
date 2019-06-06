#ifndef CMATRIX_HPP
#define CMATRIX_HPP

#include "CSize.hpp"
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
		int		m_RowCount;
		int		m_ColCount;

	protected:

	public:
		/// Constructing Matrix with [row](@ref row) and col size;
		/// \param[in] row Row Number of Matrix
		/// \param[in] col Column Number of Matrix
		CMatrix(const int row,const int col) : m_RowCount(row),m_ColCount(col) 
		{
			///Initalize memory
			m_Matrix = new T* [row];
			for(int li = 0;li < row;li++)
				m_Matrix[li] = new T[col];

			/// Fill with Zero
			for(int li = 0;li < row;li++)
				for(int lj = 0;lj < col;lj++)
					m_Matrix[li][lj] = 0;
		}

		/// A Copy Constructor
		/// \param[in] mat Matrix to be copied
		CMatrix(const CMatrix & mat) : m_RowCount(mat.m_RowCount),m_ColCount(mat.m_ColCount) 
		{
			///Initalize memory
			m_Matrix = new T* [m_RowCount];
			for(int li = 0;li < m_RowCount;li++)
				m_Matrix[li] = new T[m_ColCount];

			//Memory Copy
			for(int li = 0;li < m_RowCount;li++)
				for(int lj = 0;lj < m_ColCount;lj++)
					m_Matrix[li][lj] = mat.m_Matrix[li][lj];

		}

		/// Releasing memory and all desctructing stuff ~CMatrix(); 
		~CMatrix()
		{
			for(int li = 0;li < m_ColCount;li++)
				delete [](m_Matrix[li]);
			delete []m_Matrix;
			m_Matrix = NULL;
		}
		
		/// Set Element of Matrix with array of m_row,m_col size
		void setMatrixElement(T **item)
		{

		}

		/// Set Element of Matrix at row,col with value
		void setElement(int row,int col,T value)
		{
			this->m_Matrix[row][col] = value;
		}

		/// Returning Matrix's Element at row,col
		T getElement(int row,int col)
		{
			return this->m_Matrix[row][col];
		}

		/// Return Size of Matrix
		CSize<int> getSize()
		{
			return CSize<int>(m_RowCount,m_ColCount);
		}

		/// Return Width of Matrix
		int getWidth()
		{
			return this->m_ColCount;
		}
		
		/// Return Height of Matrix
		int getHeight()
		{
			return this->m_RowCount;
		}

		//Matrix Multiplication
		CMatrix operator * (const CMatrix & operand) const
		{
			T tmp;
			CMatrix ret(m_RowCount,operand.m_ColCount);

			for(int li = 0;li < this->m_RowCount;li++)
				for(int lj = 0;lj < operand.m_ColCount;lj++)
				{
					tmp = (T)0;
					for(int lk = 0;lk < this->m_ColCount;lk++)
						tmp += this->m_Matrix[li][lk] * operand.m_Matrix[lk][lj];
					ret.m_Matrix[li][lj] = tmp;
				}
			return ret;
		}

		/// Checked : OK
		CMatrix operator * (T operand) const
		{
			CMatrix ret(m_RowCount,m_ColCount);

			for(int li = 0;li < m_RowCount;li++)
			{
				for(int lj = 0;lj < m_ColCount;lj++)
					ret.m_Matrix[li][lj] = this->m_Matrix[li][lj] * operand;
			}
			return ret;
		}

		/// Matrix Addition and SUbstraction
		CMatrix operator + (CMatrix operand) const
		{
			assert(this->m_RowCount == operand.m_RowCount && this->m_ColCount == operand.ColCount);
			CMatrix ret(operand.m_RowCount,operand.m_ColCount);

			for(int li = 0;li< m_RowCount;li++)
				for(int lj = 0;lj < m_ColCount;lj++)
					ret.m_Matrix[li][lj] = this->m_Matrix[li][lj] + operand.m_Matrix[li][lj];
			return ret;
		}

		CMatrix operator - (CMatrix operand) const
		{
			assert(this->m_RowCount == operand.m_RowCount && this->m_ColCount == operand.ColCount);
			CMatrix ret(operand.m_RowCount,operand.m_ColCount);

			for(int li = 0;li< m_RowCount;li++)
				for(int lj = 0;lj < m_ColCount;lj++)
					ret.m_Matrix[li][lj] = this->m_Matrix[li][lj] - operand.m_Matrix[li][lj];
			return ret;
		}

		/// Unary Operator Minus
		/// Checked : OK
		CMatrix operator - () const
		{
			CMatrix ret(this->m_RowCount,this->m_ColCount);

			for(int li = 0;li < this->m_RowCount;li++)
				for(int lj = 0;lj < this->m_ColCount;lj++)
					ret.m_Matrix[li][lj] = -this->m_Matrix[li][lj];

			return ret;
		}

		/// Transpose Matrix AxB into BxA
		CMatrix transpose() const
		{
			CMatrix ret(m_ColCount,m_RowCount);

			for(int li = 0;li < m_RowCount;li++)
				for(int lj = 0;lj < m_ColCount;lj++)
					ret[lj][li] = this->m_Matrix[li][lj];
			return ret;
		}

		/// Return true if m_Row == m_Col 
		bool isSquare() const
		{
			return (m_RowCount == m_ColCount);
		}

		/// Friends ostream << operator
		friend ostream & operator << (ostream & os,const CMatrix & mat)
		{
			for(int li = 0;li< mat.m_RowCount;li++)
			{
				for(int lj = 0;lj < mat.m_ColCount;lj++)
				{
					os << mat.m_Matrix[li][lj] << ' ';
				}
				os << endl;
			}
			return os;
		}
		
};

#endif
