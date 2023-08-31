#pragma once
#include "Set.hpp"
#include "UnionSet.hpp"
#include "IntersectSet.hpp"

template<typename T>
class ResultSet
{
public:
	ResultSet();

	void addSet(Set<T>* set, short addType);

	bool contains(const T& element);

private:
	Set<T>* resultSet;

	void addByUnion(Set<T>* set);
	void addByIntersect(Set<T>* set);
};

template<typename T>
inline ResultSet<T>::ResultSet() : resultSet(nullptr) {}

template<typename T>
inline void ResultSet<T>::addSet(Set<T>* set, short addType)
{
	if (!resultSet)
	{
		resultSet = set;
		return;
	}

	switch (addType)
	{
	case 0:
		delete resultSet;
		resultSet == nullptr;
		resultSet = set;
		break;

	case 1:
		addByUnion(set);
		break;

	case 2:
		addByIntersect(set);
		break;
	}
}

template<typename T>
inline bool ResultSet<T>::contains(const T& element)
{
	return resultSet->operator[](element);
}

template<typename T>
inline void ResultSet<T>::addByUnion(Set<T>* set)
{
	std::vector<Set<T>*> newSets;
	newSets.push_back(resultSet);
	newSets.push_back(set);

	Set<T>* unionSet = new UnionSet<T>(newSets);
	resultSet = unionSet;
}

template<typename T>
inline void ResultSet<T>::addByIntersect(Set<T>* set)
{
	std::vector<Set<T>*> newSets;
	newSets.push_back(resultSet);
	newSets.push_back(set);

	Set<T>* intersectSet = new IntersectSet<T>(newSets);
	resultSet = intersectSet;
}
