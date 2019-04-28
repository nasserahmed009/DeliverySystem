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