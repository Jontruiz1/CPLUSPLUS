#pragma once
#include <string>
using namespace std;
namespace MY_HASH_FUNCTIONS {
	template <typename KeyType>
	class hash
	{
	public:
		size_t  operator()(const KeyType& k) const;
	};
	//hash function for strings
	template<>
	class hash<string>
	{
	public:
		unsigned int operator()(const string& key) const
		{


			size_t hashVal = 0;
			for (char ch : key)
				hashVal = hashVal * 37 + ch;

			return  hashVal;
		}
	};
	//hash function for unsigned
	template<>
	class hash<unsigned>
	{
	public:
		unsigned operator()(const unsigned& key) const
		{
			static int count = 0;
			count++;
			unsigned value = (unsigned int)key;

			value *= value;			// square the value
			value >>= 8;				// discard the low order 8 bits
			return value;
		}
	};
	//hash function for int
	template<>
	class hash<int>
	{
	public:
		unsigned operator()(const unsigned& key) const
		{

			unsigned value = (unsigned int)key;

			value *= value;			// square the value
			value >>= 8;				// discard the low order 8 bits
			return value;
		}
	};

	//hash function for doubles
	template<>
	class hash<double>
	{
	public:
		unsigned int operator()(double key) const
		{
			int exp;
			double mant;
			unsigned int hashval;

			if (key == 0)
				hashval = 0;
			else
			{
				mant = frexp(key, &exp);
				hashval = (unsigned int)((2 * fabs(mant) - 1) * (unsigned int)~0);
			}
			return hashval;
		}
	};
}

