#pragma once
#include "Set.hpp"
#include <fstream>
#include <vector>
#include "NormalSet.hpp"
#include "SubstringCriteria.hpp"
#include "ConcatCriteria.h"

template <typename T>
class FactoryReader
{
public:
	Set<T>* readSet(std::ifstream& binaryFileReader, short stringsCount, short setType);

	static FactoryReader<T>* getInstance();
	static void freeInstance();

private:
	FactoryReader() = default;

	FactoryReader(const FactoryReader<T>& other) = delete;
	FactoryReader<T>& operator= (const FactoryReader<T>& other) = delete;

	static FactoryReader<T>* instance;

private:
	Set<T>* readNormalSet(std::ifstream& binaryFileReader, short stringsCount) const;
	Set<T>* readIntervalSet(std::ifstream& binaryFileReader, short stringsCount) const;
	Set<T>* readSubstringCriteriaSet(std::ifstream& binaryFileReader, short stringsCount) const;
	Set<T>* readConcatCriteriaSet(std::ifstream& binaryFileReader, short stringsCount) const;
	Set<T>* readIntersectOfIntervalSets(std::ifstream& binaryFileReader, short stringsCount) const;
	Set<T>* readUnionOfIntervalSets(std::ifstream& binaryFileReader, short stringsCount) const;
};

template<typename T>
FactoryReader<T>* FactoryReader<T>::instance = nullptr;

template<typename T>
inline FactoryReader<T>* FactoryReader<T>::getInstance()
{
	if (!instance)
	{
		instance = new FactoryReader<T>();
	}

	return instance;
}

template<typename T>
inline void FactoryReader<T>::freeInstance()
{
	delete instance;
	instance = nullptr;
}

template<typename T>
inline Set<T>* FactoryReader<T>::readSet(std::ifstream& binaryFileReader, short stringsCount, short setType)
{
	switch (setType)
	{
	case 0: return readNormalSet(binaryFileReader, stringsCount);
	case 1: return readIntervalSet(binaryFileReader, stringsCount);
	case 2: return readSubstringCriteriaSet(binaryFileReader, stringsCount);
	case 3: return readConcatCriteriaSet(binaryFileReader, stringsCount);
	case 4: return readIntersectOfIntervalSets(binaryFileReader, stringsCount);
	case 5: return readUnionOfIntervalSets(binaryFileReader, stringsCount);
	}
}

template<typename T>
inline Set<T>* FactoryReader<T>::readNormalSet(std::ifstream& binaryFileReader, short stringsCount) const
{
	std::vector<T> elements;

	for (size_t i = 0; i < stringsCount; i++)
	{
		short stringLength;
		binaryFileReader.read((char*)&stringLength, sizeof(short));

		char* string = new char[stringLength + 1];
		binaryFileReader.read(string, stringLength);

		string[stringLength] = '\0';

		T element(string);

		elements.push_back(element);
	}

	return new NormalSet<T>(elements);
}

template<typename T>
inline Set<T>* FactoryReader<T>::readIntervalSet(std::ifstream& binaryFileReader, short stringsCount) const
{
	if (stringsCount != 2)
	{
		return nullptr;
	}

	short leftIntervalLength;
	binaryFileReader.read((char*)&leftIntervalLength, sizeof(short));

	char* leftIntervalPtr = new char[leftIntervalLength + 1];
	binaryFileReader.read(leftIntervalPtr, leftIntervalLength);
	leftIntervalPtr[leftIntervalLength] = '\0';

	short rightIntervalLength;
	binaryFileReader.read((char*)&rightIntervalLength, sizeof(short));

	char* rightIntervalPtr = new char[rightIntervalLength + 1];
	binaryFileReader.read(rightIntervalPtr, rightIntervalLength);
	rightIntervalPtr[rightIntervalLength] = '\0';

	T leftInterval(leftIntervalPtr);
	T rightInterval(rightIntervalPtr);

	return new IntervalSet<T>(leftInterval, rightInterval);
}


template<typename T>
inline Set<T>* FactoryReader<T>::readSubstringCriteriaSet(std::ifstream& binaryFileReader, short stringsCount) const
{
	SubstringCriteria<T> substringCriteria;

	for (size_t i = 0; i < stringsCount; i++)
	{
		short stringLength;
		binaryFileReader.read((char*)&stringLength, sizeof(short));

		char* string = new char[stringLength + 1];
		binaryFileReader.read(string, stringLength);

		string[stringLength] = '\0';

		T element(string);

		substringCriteria.addElement(element);
	}

	// Set<T>* crit = new CriteriaSet<T, SubstringCriteria<T>>(substringCriteria);

	// std::cout << crit->operator[]("blablacfmioop.datskrr");
	// std::cout << crit->operator[]("petarrrr.........ivan.union    .datskrr");
	// std::cout << crit->operator[]("llllllllllllleftInterval.dattttttttttttt");

	return new CriteriaSet<T, SubstringCriteria<T>>(substringCriteria);
}

template<typename T>
inline Set<T>* FactoryReader<T>::readConcatCriteriaSet(std::ifstream& binaryFileReader, short stringsCount) const
{
	ConcatCriteria<T> concatCriteria;

	for (size_t i = 0; i < stringsCount; i++)
	{
		short stringLength;
		binaryFileReader.read((char*)&stringLength, sizeof(short));

		char* string = new char[stringLength + 1];
		binaryFileReader.read(string, stringLength);

		string[stringLength] = '\0';

		T element(string);

		concatCriteria.addElement(element);
	}

	/*Set<T>* crit = new CriteriaSet<T, ConcatCriteria<T>>(concatCriteria);

	std::cout << crit->operator[]("fmioop.datpetar.dat");
	std::cout << crit->operator[]("fmioop.dativan.union");
	std::cout << crit->operator[]("fmioop.dativan.unionn");
	std::cout << crit->operator[]("rightInterval.datleftInterval.dat");
	std::cout << crit->operator[]("rrightInterval.datleftInterval.dat");*/

	return new CriteriaSet<T, ConcatCriteria<T>>(concatCriteria);
}

template<typename T>
inline Set<T>* FactoryReader<T>::readIntersectOfIntervalSets(std::ifstream& binaryFileReader, short stringsCount) const
{
	if (stringsCount % 2 != 0)
	{
		return nullptr;
	}

	std::vector<Set<T>*> sets;

	for (size_t i = 0; i < stringsCount / 2; i++)
	{
		Set<T>* intervalSet = readIntervalSet(binaryFileReader, 2);
		sets.push_back(intervalSet);
	}

	//Set<T>* set = new IntersectSet<T>(sets);

	//std::cout << set->operator[]("Grapes");	    // 1
	//std::cout << set->operator[]("Igloo");		// 1
	//std::cout << set->operator[]("Jigsaw");	    // 1
	//std::cout << set->operator[]("Kite");		    // 1
	//std::cout << set->operator[]("Lemon");		// 0
	//std::cout << set->operator[]("Dance");		// 0
	//std::cout << set->operator[]("Apple");		// 0
	//std::cout << set->operator[]("Parrot");       // 0

	return new IntersectSet<T>(sets);
}

template<typename T>
inline Set<T>* FactoryReader<T>::readUnionOfIntervalSets(std::ifstream& binaryFileReader, short stringsCount) const
{
	if (stringsCount % 2 != 0)
	{
		return nullptr;
	}

	std::vector<Set<T>*> sets;

	for (size_t i = 0; i < stringsCount / 2; i++)
	{
		Set<T>* intervalSet = readIntervalSet(binaryFileReader, 2);
		sets.push_back(intervalSet);
	}

	// Set<T>* set = new UnionSet<T>(sets);
	// 
	// std::cout << set->operator[]("Apple");		 // 0
	// std::cout << set->operator[]("Igloo");		 // 1
	// std::cout << set->operator[]("Jigsaw");		 // 1
	// std::cout << set->operator[]("Kite");		 // 1
	// std::cout << set->operator[]("Lemon");		 // 1
	// std::cout << set->operator[]("Dance");		 // 1
	// std::cout << set->operator[]("Quilt");	     // 0

	return new UnionSet<T>(sets);
}

