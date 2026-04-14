#include <iostream>
#include <array>
#include <cmath>

using namespace std;

void AppleSorting()
{
	struct Apple
	{
		string Name;
		int Size = 0;
		int Worm = 0;
	};

	array<Apple, 6> Apples =
	{ {
		{"A",10,0}, {"B",2,0}, {"C",8,0}, {"D",5,0}, {"E",1,0}, {"F",7,0}
		/*{ "A",5,1 }, {"B",5,5}, {"C",5,0}, {"D",5,3}, {"E",5,2}, {"F",5,4}*/
		/*{ "A",10,0 }, {"B",9,0}, {"C",8,0}, {"D",7,0}, {"E",6,0}, {"F",5,0}*/
		/*{ "A",1,0 }, {"B",2,0}, {"C",3,0}, {"D",4,0}, {"E",5,0}, {"F",6,0}*/
		/*{ "A",10,10 }, {"B",1,0}, {"C",5,5}, {"D",2,0}, {"E",8,8}, {"F",3,0}*/
		/*{ "A",5,1 }, {"B",5,1}, {"C",5,1}, {"D",5,1}, {"E",5,1}, {"F",5,1}*/
		/*{ "Big-Wormy",20,5 }, {"Small-Clean",2,0}, {"Mid-Clean",10,0}, {"Huge-Wormy",50,10}, {"Tiny",1,0}, {"A",5,0}*/
		/*{"Bad1",5,2}, {"Bad2",6,1}, {"Bad3",3,3}, {"Bad4",10,5}, {"Bad5",1,1}, {"Bad6",2,2}*/
		/*{ "G1",10,0 }, {"B1",10,1}, {"G2",5,0}, {"B2",5,1}, {"G3",1,0}, {"B3",1,1}*/
		/*{ "God",100,0 }, {"Devil",1,100}, {"A",50,0}, {"B",2,1}, {"C",10,0}, {"D",5,5}*/
	} };

	auto SortBySizePredicate = [](const Apple& a, const Apple& b)
		{
			return a.Size > b.Size;
		};

	auto SortByWormPredicate = [SortBySizePredicate](const Apple& a, const Apple& b)
		{
			if (a.Worm == b.Worm)
			{
				return SortBySizePredicate(a, b);
			}
			return a.Worm < b.Worm;
		};

	auto SortByQualityPredicate = [SortByWormPredicate, SortBySizePredicate](const Apple& a, const Apple& b)
		{
			if (a.Worm == 0 && b.Worm > 0)
			{
				return true;
			}
			if (a.Worm > 0 && b.Worm == 0)
			{
				return false;
			}
			if (a.Worm > 0 && b.Worm > 0)
			{
				return SortByWormPredicate(a, b);
			}
			if (a.Worm == 0 and b.Worm == 0)
			{
				return SortBySizePredicate(a, b);
			}
			return false;
		};

	for (int Round = 0; Round < Apples.size(); Round++)
	{
		for (int AppleIdx = 0; AppleIdx < Apples.size(); AppleIdx++)
		{
			if (SortByQualityPredicate(Apples[Round], Apples[AppleIdx]))
			{
				swap(Apples[Round], Apples[AppleIdx]);
			}
		}
	}

	for (Apple& Apply : Apples)
	{
		cout << Apply.Name << " => " << "Size : " << Apply.Size << ",Worm : " << Apply.Worm << endl;

	}
}

const int ArraySize = 5;

void Permutation(array<char, ArraySize>& Array, int Start, int End)
{
	if (Start == End)
	{
		for (char c : Array)
		{
			cout << c << " ";
		}
		cout << endl;
		return;
	}
	for (int index = Start; index <= End; index++)
	{
		swap(Array[Start], Array[index]);
		Permutation(Array, Start + 1, End);
		swap(Array[Start], Array[index]);
	}
}

int main()
{
	array<char, ArraySize> Array = { 'a','b','c','d','e'};
	Permutation(Array, 0 , ArraySize - 1);
}

