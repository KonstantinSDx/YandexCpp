#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>


int main ()
{
	std::string StringX = "Start";
	std::map<std::string, int>WordMap;
	std::string TempString = "";
	unsigned int NumberOfWord;
	std::cin >> NumberOfWord;
	std::cin.ignore(32768, '\n');
	
	while ( !StringX.empty() )
	{
		std::getline(std::cin, StringX);
		for ( unsigned int i=0; i < StringX.size(); i++)
		{
			if (StringX[i] != ' ')
			{
				TempString = TempString + StringX[i];
			}
			
			if (StringX[i] == ' ')
			{
				if ( !TempString.empty() )
				{
				   WordMap[TempString]++;
	    		   TempString.clear();	
				}
			}
			
			if ( i == (StringX.size()-1) )
			{
				if ( !TempString.empty() )
				{
				   WordMap[TempString]++;
	    		   TempString.clear();	
				}
			}
		}		
	}
	
	std::vector<std::pair<int, std::string>>VectorSortedBySecond;
	for ( auto ValueF : WordMap )
	{
		std::pair<int, std::string>TempPair(ValueF.second, ValueF.first);
		VectorSortedBySecond.emplace_back(TempPair);
	}
		
	std::sort (VectorSortedBySecond.begin(), VectorSortedBySecond.end(), 
	[]( std::pair<int, std::string> ValueA, std::pair<int, std::string> ValueB)->bool {  if ( ValueA.first > ValueB.first  ) return true; 
	                                                                                     else return false;  } );
    for (unsigned int i=0; i<NumberOfWord ; i++)
    {
    	std::cout << VectorSortedBySecond[i].second << " " << VectorSortedBySecond[i].first << std::endl;
    }
	
	return 0;
}
