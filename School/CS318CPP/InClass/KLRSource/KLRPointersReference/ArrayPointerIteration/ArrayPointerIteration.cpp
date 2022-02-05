// ArrayPointerIteration
#include <iostream>
#include <iterator> // to use size
#include <algorithm>
using namespace std;

bool isVowel(char ch)
{
	switch (tolower(ch))
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

int main()
{
	char name[]{ "Follow the Yellow Brick Road to Oz and the Emerald City" };
	int arrayLength{ static_cast<int>(size(name)) };
	int numVowels{ 0 };

	for (char* ptr{ name }; ptr < (name + arrayLength); ++ptr)
	{
		if (isVowel(*ptr))
		{
			++numVowels;
		}
	}

	cout << name << " has " << numVowels << " vowels.\n";

	// algorithms library has std::count_if.
	// Counts elements that meet a condition. 
	// The entire for loop can be replaced with this one statement

	auto vowelCount{ count_if(begin(name), end(name), isVowel) };

	cout << name << " has " << vowelCount << " vowels.\n";

	return 0;
}

