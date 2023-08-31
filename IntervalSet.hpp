#pragma once
#include "Set.hpp"

template<typename T>
class IntervalSet : public Set<T>
{
public:
	IntervalSet(T left, T right);

	bool operator[](T element) const override;

private:
	T left;
	T right;
};

template<typename T>
inline IntervalSet<T>::IntervalSet(T left, T right)
	: left(left), right(right)
{
	if (right > left)
	{
		this->right = right;
		this->left = left;
	}
	else
	{
		this->right = left;
		this->left = right;
	}
}

template<typename T>
inline bool IntervalSet<T>::operator[](T element) const
{
	return (element >= left) && (element <= right);
}
