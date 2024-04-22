#include <iostream>
#include <algorithm>
#include <vector>


int main()
{

    std::vector<int>VectorX;
    for ( int i=0; i<5; i++)
    {
    	int ValueX;
    	std::cin >> ValueX;
    	VectorX.push_back(ValueX);
    }
    
    for (int A : VectorX)
    {
    	std::cout << A << " ";
    }

	
/*	
	unsigned int n;
	unsigned int k;
	int Num;
	std::cin >> n >> k;
	std::vector<int>ArrayOneSorted;
	std::vector<int>ArrayTwoUnsorted;
	for (unsigned int i = 0; i<n; i++ )
	{
		std::cin >> Num;
		ArrayOneSorted.push_back(Num);
	}
	std::sort ( ArrayOneSorted.begin(), ArrayOneSorted.end() );
	
	for (unsigned int i = 0; i<k; i++ )
	{
		std::cin >> Num;
		ArrayTwoUnsorted.push_back(Num);
	}
	
	for (unsigned int i = 0; i<k; i++ )
	{
		auto IterFindLower = std::lower_bound(ArrayOneSorted.begin(), ArrayOneSorted.end(), ArrayTwoUnsorted[i]);
		if ( IterFindLower == ArrayOneSorted.begin() ) std::cout << *IterFindLower << std::endl;
        else
		{
			auto IterMinus = IterFindLower;
			IterMinus--;
			if ( abs( ArrayTwoUnsorted[i] - *IterMinus ) <= abs( *IterFindLower - ArrayTwoUnsorted[i] ) ) std::cout << *IterMinus << std::endl;
            else std::cout << *IterFindLower << std::endl;
		}
	}
*/	
	return 0;
}
