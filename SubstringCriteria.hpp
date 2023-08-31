#pragma once
#include <vector>

template<typename T>
class SubstringCriteria
{
public:
	void addElement(const T& element);
	bool operator()(const T& element)const;

private:
	std::vector<T> elements;

	bool isSubstring(const T& pattern, const T& element) const;
};

template<typename T>
inline void SubstringCriteria<T>::addElement(const T& element)
{
	elements.push_back(element);
}

template<typename T>
inline bool SubstringCriteria<T>::operator()(const T& element) const
{
	unsigned elementsCount = element.size();

	for (size_t i = 0; i < elementsCount; i++)
	{
		if (isSubstring(elements[i], element))
		{
			return true;
		}
	}

	return false;
}

template<typename T>
inline bool SubstringCriteria<T>::isSubstring(const T& pattern, const T& element) const
{
	unsigned patternIndex = 0;
	unsigned elementIndex = 0;

	while (true)
	{
		if (!pattern[patternIndex])
		{
			return true;
		}

		if (!element[elementIndex])
		{
			return false;
		}

		char elementSymbol = element[elementIndex];
		char patternSymbol = pattern[patternIndex];

		if (element[elementIndex] == pattern[patternIndex])
		{
			elementIndex++;
			patternIndex++;
		}
		else
		{
			if (element[elementIndex] == pattern[0])
			{
				patternIndex = 0;
			}
			else
			{
				patternIndex = 0;
				elementIndex++;
			}
		}
	}
}
