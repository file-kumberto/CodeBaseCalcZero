// CalculateZeroInBinaryNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

int calcBitZero(int number)
{
	int highBit = 0;
	for (; number >= std::pow(2.0, highBit); ++highBit);

	const int mask = 1;
	int countZero = 0;
	bool startCount = false;
	for (int indexOne = 0; indexOne < highBit; ++indexOne)
	{
		if (number & mask == 1)
		{
			startCount = !startCount;
			if (!startCount)
			{
				break;
			}
		}
		else
		{
			if (startCount)
			{
				++countZero;
			}
		}
		number >>= 1;
	}
	return countZero;
}

int main()
{
	std::cout << calcBitZero(512) << std::endl;
}
