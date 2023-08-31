#pragma once
#include "Set.hpp"
#include <vector>

template<typename T>
class UnionSet : public  Set<T>
{
public:
	UnionSet(const std::vector<Set<T>*>& inputSets);

	bool operator[](T element) const override;

private:
	std::vector<Set<T>*> sets;
};

template<typename T>
inline UnionSet<T>::UnionSet(const std::vector<Set<T>*>& sets)
	: sets(sets) {}

template<typename T>
inline bool UnionSet<T>::operator[](T element) const
{
	for (size_t i = 0; i < sets.size(); i++)
	{
		if ((*sets[i])[element])
		{
			return true;
		}
	}

	return false;
}
