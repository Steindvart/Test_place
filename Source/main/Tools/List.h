#ifndef MY_LIST
#define MY_LIST

#include "Unique_ptr.h"

namespace my
{

template<class T>
class List
{
public:
	template<class T>
	struct Node
	{
		Node()
			: m_next(nullptr)
		{}
		Node(const T& val)
			: m_next(nullptr)
			, m_val(val)
		{}

		Node<T>* m_next;
		T m_val;
	};

	List();
	~List();

	void append(const T& val);
	void pass_all() const;

	T operator[](size_t index);

private:
	Node<T>* m_head;

	size_t m_size;
};

template<class T>
List<T>::List()
	: m_head(nullptr)
	, m_size(0L)
{

}

template<class T>
List<T>::~List()
{
}

template<class T>
void List<T>::append(const T& val)
{
	m_head->m_next = new Node<T>(val);
	m_head = m_head->m_next;


}

template<class T>
T List<T>::operator[](size_t index)
{
	while (index--)
	{

	}
}

} // namespace 'my'

#endif // !MY_UNIQUE_PTR