#ifndef CMATRIX_HPP
#define CMATRIX_HPP

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
		CMatrix(int row,int col);

		/// A Copy Constructor
		/// \param[in] mat Matrix to be copied
		CMatrix(CMatrix & mat);

		/// A Move Constructor
		/// \param[in] mat Matrix to be moved
		CMatrix(CMatrix && mat);

			
		/// Releasing memory and all desctructing stuff ~CMatrix(); 
		~CMatrix();
		
		/// Set Element of Matrix with array of m_row,m_col size
		void setElement(T **item);

		/// Set Element of Matrix at row,col with value
		void setElement(int row,int col,T value);

		/// Set Matrix's Element by row
		/// @param[in] row Matrix's Row Number to bet set
		/// @param[in] ... Element Value. Should be array with m_Col Element
		void setRowLine(int row,...);

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

#endif
