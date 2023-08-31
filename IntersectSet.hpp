#pragma once
#include "Set.hpp"
#include <vector>

template <typename T>
class IntersectSet : public Set<T>
{
public:
	IntersectSet(const std::vector<Set<T>*>& sets);

	bool operator[](T element) const override;

private:
	std::vector<Set<T>*> sets;
};

template<typename T>
inline IntersectSet<T>::IntersectSet(const std::vector<Set<T>*>& sets)
	:sets(sets) {}

template<typename T>
inline bool IntersectSet<T>::operator[](T element) const
{
	unsigned setsCount = sets.size();

	for (size_t i = 0; i < setsCount; i++)
	{
		if (!(*sets[i])[element])
		{
			return false;
		}
	}

	return true;
}
