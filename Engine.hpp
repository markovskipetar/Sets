#pragma once
#include "Set.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include "FactoryReader.hpp"
#include "ResultSet.hpp"

template<typename T>
class Engine
{
public:
	void Run();

private:
	short readStringsCount(std::ifstream& binaryFileReader) const;
	short readSetData(std::ifstream& binaryFileReader) const;

	short parseAddType(short number) const;
	short parseSetType(short number) const;

	void validateSetData(short addType, short setType) const;
	bool validateSet(const Set<T>* set, const char* fileName) const;
};

template <typename T>
void Engine<T>::Run()
{
	std::ifstream textFileReader("input.txt");

	if (!textFileReader.good())
	{
		std::cout << "Reading file names failed!" << std::endl;
	}

	FactoryReader<T>* setReader = FactoryReader<T>::getInstance();
	ResultSet<T> resultSet;

	while (!textFileReader.eof())
	{
		char fileName[1024];
		textFileReader.getline(fileName, 1024);

		std::ifstream binaryFileReader(fileName, std::ios::binary);

		if (!binaryFileReader.good())
		{
			std::cout << "Reading binary file failed!" << std::endl;
		}

		short stringsCount = readStringsCount(binaryFileReader);
		short setData = readSetData(binaryFileReader);

		short addType = parseAddType(setData);
		short setType = parseSetType(setData);

		validateSetData(addType, setType);

		Set<T>* set = setReader->readSet(binaryFileReader, stringsCount, setType);

		if (validateSet(set, fileName));
		{
			resultSet.addSet(set, addType);
		}

		binaryFileReader.close();
	}

	std::cout << resultSet.contains("pppetar.date");

	FactoryReader<T>::freeInstance();
}

template<typename T>
inline short Engine<T>::readStringsCount(std::ifstream& binaryFileReader) const
{
	short stringsCount;
	binaryFileReader.read((char*)&stringsCount, sizeof(short));

	return stringsCount;
}

template<typename T>
inline short Engine<T>::readSetData(std::ifstream& binaryFileReader) const
{
	short setData;
	binaryFileReader.read((char*)&setData, sizeof(short));

	return setData;
}

template<typename T>
short Engine<T>::parseSetType(short number) const
{
	number >>= 2;

	short setType = 0;

	for (size_t i = 0; i < 14; i++)
	{
		short currentNumber = ((1 << i) & number);
		setType += currentNumber;
	}

	return setType;
}

template<typename T>
short Engine<T>::parseAddType(short number) const
{
	short addType = 0;

	for (size_t i = 0; i < 2; i++)
	{
		short currentNumber = ((1 << i) & number);
		addType += currentNumber;
	}

	return addType;
}

template<typename T>
inline void Engine<T>::validateSetData(short addType, short setType) const
{
	if (addType < 0 || addType > 2)
	{
		std::cout << "Invalid way to add the set!" << std::endl;
	}
	else if (setType < 0 || setType > 5)
	{
		std::cout << "Invalid set type!" << std::endl;
	}
}

template<typename T>
bool Engine<T>::validateSet(const Set<T>* set, const char* fileName) const
{
	if (!set)
	{
		std::cout << "Invalid set data in " << fileName << " file!" << std::endl;
		return false;
	}

	return true;
}