#pragma once
template<class T>
struct greater_ptrs
{
	constexpr bool operator()(const T& lhs, const T& rhs) const
	{
		return ((*lhs) > (*rhs));
	}
};

template<class T>
struct less_ptrs
{
	constexpr bool operator()(const T& lhs, const T& rhs) const
	{
		return ((*lhs) < (*rhs));
	}
};

template<class T>
struct greater_moto_ptrs
{
	constexpr bool operator()(const T& lhs, const T& rhs) const
	{
		if (lhs->get_broken() == false && rhs->get_broken() == true)
			return true;
		else if (lhs->get_broken() == true && rhs->get_broken() == false)
			return false;
		else
			return (lhs->get_speed() > rhs->get_speed());
	}
};