#include <iostream>
#include <string>
#include "NormalSet.hpp"
#include "IntervalSet.hpp"
#include "CriteriaSet.hpp"
#include "IntersectSet.hpp"
#include "UnionSet.hpp"
#include "Engine.hpp"

void createFirstNormalSet()
{
	std::ofstream file("firstNormalSet.dat", std::ios::binary);

	short stringsCount = 3;
	short setData = 0;

	file.write((const char*)&stringsCount, sizeof(short));
	file.write((const char*)&setData, sizeof(short));

	const char* text1 = "fmioop.dat";
	short text1Length = 10;

	file.write((const char*)&text1Length, sizeof(short));
	file.write((const char*)text1, text1Length);

	const char* text2 = "ppetar.date";
	short text2Length = 11;

	file.write((const char*)&text2Length, sizeof(short));
	file.write((const char*)text2, text2Length);

	const char* text3 = "ivan.union";
	short text3Length = 10;

	file.write((const char*)&text3Length, sizeof(short));
	file.write((const char*)text3, text3Length);

	file.flush();
	file.close();
}
void createSecondNormalSet()
{
	std::ofstream file2("secondNormalSet.dat", std::ios::binary);

	short stringsCount2 = 2;
	short setData2 = 1;

	file2.write((const char*)&stringsCount2, sizeof(short));
	file2.write((const char*)&setData2, sizeof(short));

	/*const char* text4 = "fmi.dat";
	short text4Length = 7;*/
	const char* text4 = "fmioop.dat";
	short text4Length = 10;

	file2.write((const char*)&text4Length, sizeof(short));
	file2.write((const char*)text4, text4Length);

	const char* text5 = "demo.asd";
	short text5Length = 8;

	file2.write((const char*)&text5Length, sizeof(short));
	file2.write((const char*)text5, text5Length);

	file2.flush();
	file2.close();
}
void createIntervalSet()
{
	std::ofstream file("intervalSet.dat", std::ios::binary);

	short stringsCount = 2;
	short setData = 6;

	file.write((const char*)&stringsCount, sizeof(short));
	file.write((const char*)&setData, sizeof(short));

	const char* text1 = "rightInterval.dat";
	short text1Length = 17;

	file.write((const char*)&text1Length, sizeof(short));
	file.write((const char*)text1, text1Length);

	const char* text2 = "leftInterval.dat";
	short text2Length = 16;

	file.write((const char*)&text2Length, sizeof(short));
	file.write((const char*)text2, text2Length);

	file.flush();
	file.close();
}
void createCriteriaSubStringSet()
{
	std::ofstream file("criteriaSubStringSet.dat", std::ios::binary);

	short stringsCount = 5;
	short setData = 10;

	file.write((const char*)&stringsCount, sizeof(short));
	file.write((const char*)&setData, sizeof(short));

	const char* text1 = "fmioop.dat";
	short text1Length = 10;

	file.write((const char*)&text1Length, sizeof(short));
	file.write((const char*)text1, text1Length);

	const char* text2 = "petar.dat";
	short text2Length = 9;

	file.write((const char*)&text2Length, sizeof(short));
	file.write((const char*)text2, text2Length);

	const char* text3 = "ivan.union";
	short text3Length = 10;

	file.write((const char*)&text3Length, sizeof(short));
	file.write((const char*)text3, text3Length);

	const char* text4 = "rightInterval.dat";
	short text4Length = 17;

	file.write((const char*)&text4Length, sizeof(short));
	file.write((const char*)text4, text4Length);

	const char* text5 = "leftInterval.dat ";
	short text5Length = 16;

	file.write((const char*)&text5Length, sizeof(short));
	file.write((const char*)text5, text5Length);

	file.flush();
	file.close();
}
void createCriteriaConcatSet()
{
	std::ofstream file("criteriaConcatSet.dat", std::ios::binary);

	short stringsCount = 5;
	short setData = 13;

	file.write((const char*)&stringsCount, sizeof(short));
	file.write((const char*)&setData, sizeof(short));

	const char* text1 = "fmioop.dat";
	short text1Length = 10;

	file.write((const char*)&text1Length, sizeof(short));
	file.write((const char*)text1, text1Length);

	const char* text2 = "petar.dat";
	short text2Length = 9;

	file.write((const char*)&text2Length, sizeof(short));
	file.write((const char*)text2, text2Length);

	const char* text3 = "ivan.union";
	short text3Length = 10;

	file.write((const char*)&text3Length, sizeof(short));
	file.write((const char*)text3, text3Length);

	const char* text4 = "rightInterval.dat";
	short text4Length = 17;

	file.write((const char*)&text4Length, sizeof(short));
	file.write((const char*)text4, text4Length);

	const char* text5 = "leftInterval.dat";
	short text5Length = 16;

	file.write((const char*)&text5Length, sizeof(short));
	file.write((const char*)text5, text5Length);

	file.flush();
	file.close();
}
void createIntersectOfIntervalSets()
{
	std::ofstream file("intersectOfIntervalSets.dat", std::ios::binary);

	short stringsCount = 6;
	short setData = 16;

	file.write((const char*)&stringsCount, sizeof(short));
	file.write((const char*)&setData, sizeof(short));

	const char* text1 = "Grapes";
	short text1Length = 6;

	file.write((const char*)&text1Length, sizeof(short));
	file.write((const char*)text1, text1Length);

	const char* text2 = "Quilt";
	short text2Length = 5;

	file.write((const char*)&text2Length, sizeof(short));
	file.write((const char*)text2, text2Length);

	const char* text3 = "Apple";
	short text3Length = 5;

	file.write((const char*)&text3Length, sizeof(short));
	file.write((const char*)text3, text3Length);

	const char* text4 = "Lemon";
	short text4Length = 5;

	file.write((const char*)&text4Length, sizeof(short));
	file.write((const char*)text4, text4Length);

	const char* text5 = "Cake";
	short text5Length = 4;

	file.write((const char*)&text5Length, sizeof(short));
	file.write((const char*)text5, text5Length);

	const char* text6 = "Kite";
	short text6Length = 4;

	file.write((const char*)&text6Length, sizeof(short));
	file.write((const char*)text6, text6Length);

	file.flush();
	file.close();
}
void createUnionOfIntervalSets()
{
	std::ofstream file("unionOfIntervalSets.dat", std::ios::binary);

	short stringsCount = 6;
	short setData = 20;

	file.write((const char*)&stringsCount, sizeof(short));
	file.write((const char*)&setData, sizeof(short));

	const char* text1 = "Grapes";
	short text1Length = 6;

	file.write((const char*)&text1Length, sizeof(short));
	file.write((const char*)text1, text1Length);

	const char* text2 = "Parrot";
	short text2Length = 6;

	file.write((const char*)&text2Length, sizeof(short));
	file.write((const char*)text2, text2Length);

	const char* text3 = "Basket";
	short text3Length = 6;

	file.write((const char*)&text3Length, sizeof(short));
	file.write((const char*)text3, text3Length);

	const char* text4 = "Lemon";
	short text4Length = 5;

	file.write((const char*)&text4Length, sizeof(short));
	file.write((const char*)text4, text4Length);

	const char* text5 = "Cake";
	short text5Length = 4;

	file.write((const char*)&text5Length, sizeof(short));
	file.write((const char*)text5, text5Length);

	const char* text6 = "Kite";
	short text6Length = 4;

	file.write((const char*)&text6Length, sizeof(short));
	file.write((const char*)text6, text6Length);

	file.flush();
	file.close();
}

int main()
{
	createFirstNormalSet();
	createSecondNormalSet();
	createIntervalSet();
	createCriteriaSubStringSet();
	/*createCriteriaConcatSet();
	createIntersectOfIntervalSets();
	createUnionOfIntervalSets();*/

	Engine<std::string> e;
	e.Run();
}
