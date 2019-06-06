#ifndef CSIZE_HPP
#define CSIZE_HPP

#include <ostream>

using namespace std;

template <typename T>
class CSize
{
	private:
		T	m_Width;
		T	m_Height;
	public:
		CSize(T width,T height) : m_Width(width),m_Height(height)
		{
		}

		T getWidth()
		{
			return m_Width;
		}

		T getHeight()
		{
			return m_Height;
		}

		bool operator == (const CSize<T> & operand)
		{
			return (m_Width == operand.m_Width && m_Height == operand.m_Height);
		}

		friend  ostream & operator << (ostream & os,const CSize & Size)
		{
			os << Size.m_Width << 'x' << Size.m_Height;
			return os;
		}
};

#endif 
