#pragma once
#include "Set.hpp"

template<typename T, typename CriteriaType>
class CriteriaSet : public Set<T>
{
public:
	CriteriaSet(CriteriaType belongToSet);

	bool operator[](T element) const override;

private:
	CriteriaType belongToSet;
};

template<typename T, typename CriteriaType>
inline CriteriaSet<T, CriteriaType>::CriteriaSet(CriteriaType belongToSet)
	: belongToSet(belongToSet) {}

template<typename T, typename CriteriaType>
inline bool CriteriaSet<T, CriteriaType>::operator[](T element) const
{
	return belongToSet(element);
}
