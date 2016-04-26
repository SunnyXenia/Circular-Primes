#include <iostream>
#include <math.h>

bool IsPrime(const int& i_number)
{
	for (int i = 2; i <= sqrt(i_number); ++i)
	{
		if (i_number % i == 0)
			return false;
	}
	return true;
}

int NumberOfDigits(const int& i_number)
{
	int counter = 1;

	for (int i = 10; i < 1000000; i *= 10)
	{
		if (i_number / i != 0)
			++counter;
	}

	return counter;
}

bool IsCircular(const int& prime_number)
{
	int num_of_digits = NumberOfDigits(prime_number);
	int some_num = prime_number;

	for (int i = 0; i < num_of_digits-1; ++i)
	{
		some_num = std::pow(10, num_of_digits - 1)*(some_num % 10) + some_num / 10;
		if (!IsPrime(some_num))
			return false;
	}

	return true;
}

int main()
{
	int counter = 0;

	for (int i = 2; i < 1000000; ++i)
	{
		if (IsPrime(i))
		{
			if (IsCircular(i))
			{
				std::cout << i << " ";
				++counter;
			}
		}
	}
	std::cout << std::endl;
	std::cout << "Number of circular numbers: " << counter << std::endl;

	return 0;
}