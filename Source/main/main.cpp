#include "stdafx.h"

#include "Tools/Unique_ptr.h"
#include "Tools/List.h"
#include "Tools/ScopeGuard.h"

template<class T>
class Auto_ptr3
{
	T* m_ptr;
public:
	Auto_ptr3(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr3()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3(const Auto_ptr3& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr3(Auto_ptr3&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr3& operator=(Auto_ptr3&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() 
	{ 
		std::cout << "Resource acquired\n"; 
	}
	~Resource() 
	{
		std::cout << "Resource destroyed\n"; 
	}
};

Auto_ptr3<Resource> generateResource()
{
	Auto_ptr3<Resource> res(new Resource);
	return res; // this return value will invoke the copy constructor
}

class Base
{
public:
	virtual void foo() { std::cout << "Base"; }
};

class Child : public Base
{
public:
	//void foo() override { std::cout << "Child"; }
};

int main()
{
	my::ScopeGuard s([]() { std::cout << "Hello!"; });
	my::unique_ptr<int> my_p(new int(5));

	//my::List<int> li;
	//my::List<double> lid;

	//std::cout << *my_p << std::endl;

	return 0;
}