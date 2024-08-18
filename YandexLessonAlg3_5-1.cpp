#include <iostream>
#include <cstdlib>

int main()
{
	unsigned int NumberArrayElements;
	std::cin >> NumberArrayElements;
	int IntegerArray[NumberArrayElements];
	for (size_t i = 0; i < NumberArrayElements; i++)
	{
		std::cin >> IntegerArray[i];
	}
	
	for ( size_t i = 0; i < ( NumberArrayElements - 1 ); i++)
	{
		int MinValueIndex = i;
		int MinValue = IntegerArray[i];
		for ( size_t j = ( i+1 ); j < NumberArrayElements; j++ )
		{
			if ( MinValue > IntegerArray[j] ) 
			{
				MinValue = IntegerArray[j];
				MinValueIndex = j;
			}
		}
		
		if (MinValueIndex != i) std::swap ( IntegerArray[i], IntegerArray[MinValueIndex] );
	}
	
	for ( size_t i = 0; i < NumberArrayElements; i++)
	{
		if ( i < ( NumberArrayElements - 1) ) std:: cout << IntegerArray[i] << " ";
		else std:: cout << IntegerArray[i];
	}	
	
	return 0;
}