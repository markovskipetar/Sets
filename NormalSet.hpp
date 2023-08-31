#pragma once
#include "Set.hpp"
#include <vector>

template <typename T>
class NormalSet : public Set<T>
{
public:
	NormalSet(const std::vector<T>& inputElements);

	bool operator[](T element) const override;

private:
	std::vector<T> elements;

	bool belongs(T elementToCheck) const;
};

template<typename T>
inline NormalSet<T>::NormalSet(const std::vector<T>& inputElements)
{
	unsigned inputElementsCount = inputElements.size();

	for (size_t i = 0; i < inputElementsCount; i++)
	{
		if (!belongs(inputElements[i]))
		{
			elements.push_back(inputElements[i]);
		}
	}
}

template<typename T>
bool NormalSet<T>::operator[](T element) const
{
	return belongs(element);
}

template<typename T>
inline bool NormalSet<T>::belongs(T elementToFind) const
{
	unsigned elementsCount = elements.size();

	for (size_t i = 0; i < elementsCount; i++)
	{
		if (elements[i] == elementToFind)
		{
			return true;
		}
	}

	return false;
}
