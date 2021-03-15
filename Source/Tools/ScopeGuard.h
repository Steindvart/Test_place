#ifndef MY_SCOPE_GUARD
#define MY_SCOPE_GUARD

#include <functional>

namespace my
{

class ScopeGuard
{
public:
	explicit ScopeGuard(std::function<void()>&& f)
		: m_f(std::move(f)) 
	{ }
	ScopeGuard(ScopeGuard&& other) noexcept
		: m_f(nullptr)
	{
		std::swap(m_f, other.m_f);
	}

	ScopeGuard(const ScopeGuard&)            = delete;
	ScopeGuard& operator=(const ScopeGuard&) = delete;

	void dismiss() 
	{
		m_f = nullptr;
	}

	~ScopeGuard() 
	{
		if (m_f)
			m_f();
	}

private:
	std::function<void()> m_f;
};

} // !namespace 'my'

#endif // !MY_SCOPE_GUARD