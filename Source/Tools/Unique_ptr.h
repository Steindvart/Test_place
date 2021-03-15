#ifndef MY_UNIQUE_PTR
#define MY_UNIQUE_PTR

namespace my
{

template<class T>
class unique_ptr
{
public:
	unique_ptr();

	~unique_ptr();

private:
	T* m_res;
};

} // namespace 'my'


#endif // !MY_UNIQUE_PTR