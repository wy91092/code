#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>
class MyVector 
{
	private:
		int m_size ;
		int m_capacity ;
		int *m_arr ;
	public:
		MyVector(int size = 0):m_size(size),m_capacity(size)
		{
				m_arr = new int[size]() ;
		}
		MyVector(const MyVector& obj):m_size(obj.m_size),m_capacity(obj.m_capacity)
		{
			m_arr = new int[m_capacity]() ;
			memmove(m_arr, obj.m_arr, sizeof(int) * obj.m_size );
		}
		MyVector(int* begin, int* end)
		{
			m_size = end - begin ;
			m_capacity = m_size ;
			m_arr = new int[m_size]() ;
			memmove(m_arr, begin, sizeof(int) * m_size) ;
		}
		MyVector& operator =(const MyVector& obj)
		{
			if( this != &obj )
			{
				if( m_capacity == 1 )
				{
				delete m_arr ;
				}else if(m_capacity > 1)
				{
					delete [] m_arr ;
				}
				m_arr = new int[obj.m_capacity]();
				memmove(m_arr, obj.m_arr, sizeof(int) * obj.m_size );
				m_size = obj.m_size ;
				m_capacity = obj.m_capacity ;
				
			}
			return *this ;
		}
		int* begin()
		{
			return m_arr ;
		}
		int* end()
		{
			return m_arr + m_size ;
		}
		int& operator [](const int index)
		{
			return m_arr[index] ;	
		}
		void push_back(const int ival)
		{
			if(m_size < m_capacity)
			{
				m_arr[m_size ++] = ival ;
			}else if(m_size == m_capacity)
			{
				
				int * tmp = m_arr ;
				m_capacity += m_capacity >> 1  + 1;
				m_arr = new int[m_capacity ]();
				if(m_size > 0)
				{
					memmove(m_arr, tmp, m_size * sizeof(int));
					m_arr[m_size ++ ] = ival ;
					if(m_size > 1)
					{
					delete [] tmp ;
					}else if(m_size == 1)
					{
						delete tmp ;
					}
				}else if(m_size == 0)
				{
					m_arr[m_size ++ ] = ival ;
				}

			}
		}
		int insert(const int pos , const int ival)
		{
			if(pos < 0 || pos >= m_size)
			{
				throw std::runtime_error("out_of_range");
				return -1 ;

			}
			if( m_size < m_capacity)
			{
				memmove(m_arr + pos + 1, m_arr + pos, (m_size - pos) * sizeof(int));
				m_arr[pos] = ival ;
				m_size ++ ;
				return pos ;
			}else if (m_size == m_capacity) 
			{
				int * tmp = m_arr ;
				m_capacity += m_capacity >> 1  + 1;
				m_arr = new int[m_capacity ]();
				memmove(m_arr, tmp, pos * sizeof(int));
				m_arr[pos] = ival ;
				memmove(m_arr + pos + 1 ,tmp + pos, (m_size - pos)* sizeof(int) );
				if(m_size == 1)
				{
					delete tmp ;
				}else 
				{
					delete [] tmp ;
				}
				m_size ++ ;
				return pos ;
				
			}
		}
		~MyVector()
		{
				if( m_capacity == 1 )
				{
					delete m_arr ;
				}else if(m_capacity > 1)
				{
					delete [] m_arr ;
				}
				m_arr = NULL ;
				m_size = 0 ;
				m_capacity = 0 ;
			
		}
		const int size() const
		{
			return m_size ;
		}
		const int capacity() const
		{
			return m_capacity ;
		}
};
#endif
