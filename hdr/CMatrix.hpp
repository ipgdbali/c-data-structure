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

			
		/// Releasing memory and all desctructing stuff
		~CMatrix();

		/// Set Element of Matrix with array of m_row,m_col size
		void setElement(T **item);

		/// Set Matrix's Element by row
		/// @param[in] row Matrix's Row Number to bet set
		/// @param[in] ... Element Value. Should be array with m_Col Element
		void setRowLine(int row,...);

		/*
		** Method Name	: operator *
		** Parameter	: Matrix that will be multiply by this
		** Return		: Matrix that has been multiplied by this and parameter
		*/
		CMatrix operator * (CMatrix operand) const;
		CMatrix operator * (int operand) const;

		/*
		** Method Name  : operator +
		** Parameter	: Matrix that will be added with this
		** Return		: Matrix that has been added by this and parameter
		*/
		CMatrix operator + (CMatrix operand) const;
		CMatrix operator - (CMatrix operand) const;

		/*
		** Method Name	: transpose
		** Parameter	: -
		** Return		: Transposed Matrix
		** Description  :
		**	Transposed Matrix means Matrix with dimension row,col become matrix with dimension col,row
		*/
		CMatrix transpose() const;

		/*
		** Method Name	: isSquare
		** Parameter	: - 
		** Return		: 
		**		- true		: if matrix dimension (row,col) is square / row = col
		**		- false		: if not above
		*/
		bool	isSquare() const;
		
		/*
		** 
		*/
		static CMatrix getIdentity();
};

#endif
