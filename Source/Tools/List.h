#ifndef MY_LIST
#define MY_LIST

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
	Node<T> m_node;

	size_t m_size;
};

} // namespace 'my'

#endif // !MY_UNIQUE_PTR