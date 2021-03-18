#ifndef MY_UNIQUE_PTR
#define MY_UNIQUE_PTR

namespace my
{

template<class T>
class unique_ptr
{
public:
	unique_ptr(T* res);
	~unique_ptr();

	T& get();

	T& operator*();

private:
	T* m_res;
};

template<class T>
unique_ptr<T>::unique_ptr(T* res)
	: m_res{ res }
{
}

template<class T>
unique_ptr<T>::~unique_ptr()
{
	delete m_res;
}

template<class T>
T& unique_ptr<T>::get()
{
	return *m_res;
}

template<class T>
T& unique_ptr<T>::operator*()
{
	return *m_res;
}

} // namespace 'my'

#endif // !MY_UNIQUE_PTR