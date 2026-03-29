#include <iostream>
#include <array>

using namespace std;

int main()
{
	struct Apple
	{
		string Name;
		int Size = 0;
		int Worm = 0;
	};

	array<Apple, 6> Apples = 
	{ {
	{"Good Apply", 6,0},
	{"Bad Apply", 5,2},
	{"Normal Apply", 10,1},
	{"Good Apply", 3,2},
	{"Bad Apply", 10,0},
	{"Normal Apply", 2,2}
	} };

	auto SortBySizePredicate = [](const Apple& a, const Apple& b) 
		{
			return a.Size > b.Size; 
		};

	auto DetectWormPredicate = [](const Apple& a)
		{
			return a.Worm > 0;
		};

	auto SortByWormPredicate = [DetectWormPredicate](const Apple& a, const Apple& b)
		{
			return DetectWormPredicate(a) and DetectWormPredicate(b);
		};

	for (int Round = 0 ;Round < Apples.size() ; Round++)
	{
		for (int AppleIdx = 0; AppleIdx < Apples.size(); AppleIdx++)
		{
			if (SortBySizePredicate(Apples[Round], Apples[AppleIdx]))
			{
				swap(Apples[Round], Apples[AppleIdx]);
			}
		}
	}

	//for (Apple& Apply : Apples)
	//{
	//	cout << Apply.Name << " => " << "Size : " << Apply.Size << ",Worm : " << Apply.Worm << endl;

	//}

	for (int Round = 0; Round < Apples.size(); Round++)
	{
		if(DetectWormPredicate(Apples[Round]) == true)
		{
			for (int AppleIdx = Round; AppleIdx < Apples.size(); 1 + AppleIdx++)
			{
				if (SortByWormPredicate(Apples[AppleIdx], Apples[Round]) == false)
				{
					swap(Apples[AppleIdx], Apples[Round]);
					break;
				}

			}
		}
	}

	for (Apple& Apply : Apples)
	{
		cout << Apply.Name << " => " << "Size : " << Apply.Size << ",Worm : " << Apply.Worm << endl;
		
	}
}

