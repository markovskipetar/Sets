#pragma once
#include <vector>
#include <iostream>

template <typename T>
class ConcatCriteria
{
public:
	void addElement(const T& element);
	bool operator()(const T& element)const;

private:
	std::vector<T> elements;

	bool isConcatenation(const T& element) const;
	bool compare(const T& element, const T& first, const T& second) const;
};

template<typename T>
inline void ConcatCriteria<T>::addElement(const T& element)
{
	elements.push_back(element);
}

template<typename T>
inline bool ConcatCriteria<T>::operator()(const T& element) const
{
	return isConcatenation(element);
}

template<typename T>
inline bool ConcatCriteria<T>::isConcatenation(const T& element) const
{
	unsigned elementsCount = elements.size();

	for (size_t i = 0; i < elementsCount; i++)
	{
		for (size_t j = 0; j < elementsCount; j++)
		{
			if (i != j && compare(element, elements[i], elements[j]))
			{
				return true;
			}
		}
	}

	return false;
}

template<typename T>
inline bool ConcatCriteria<T>::compare(const T& element, const T& first, const T& second) const
{
	unsigned elementIndex = 0;

	unsigned firstLength = first.size();

	for (size_t i = 0; i < firstLength; i++)
	{
		if (!element[elementIndex])
		{
			return false;
		}

		if (element[elementIndex++] != first[i])
		{
			return false;
		}
	}

	unsigned secondLength = second.size();

	for (size_t i = 0; i < secondLength; i++)
	{
		if (!element[elementIndex])
		{
			return false;
		}

		if (element[elementIndex++] != second[i])
		{
			return false;
		}
	}

	if (element[elementIndex])
	{
		return false;
	}

	return true;
}
