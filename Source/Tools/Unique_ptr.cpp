#include "Unique_ptr.h"

using namespace my;

template<class T>
unique_ptr<T>::unique_ptr()
	: m_res{ new T }
{
}

template<class T>
unique_ptr<T>::~unique_ptr()
{
	delete m_res;
}