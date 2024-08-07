#include <iostream>
#include <cstdlib>
#include <list>
#include <forward_list>

int main()
{		
	size_t NumberOfInterval;
	std::pair<int, int> ElementX;
	std::cin >> NumberOfInterval;
	std::list<std::pair<int, int>>ElementList;
	std::list<std::pair<int, int>>ElementListFinal;
	int MaxCycle = 0;	
	for (size_t i=0; i<NumberOfInterval; i++ )
	{
		std::cin >> ElementX.first >> ElementX.second;
		if ( ElementX.second > MaxCycle ) MaxCycle = ElementX.second+1;
		ElementList.push_back(ElementX);
	}
	
	std::cout << "Stage End" << std::endl;

	
	for (std::pair<int, int> ValX : ElementList)
	{
		std::cout << ValX.first << "  " << ValX.second << std::endl;
	}
	
/*
for (size_t i = 1; i<MaxCycle;)
	{
		std::cout << std::endl;     // Trassing
		std::cout << "**********  Now i - " << i << "  **********"<< std::endl;     // Trassing
		int Vsecond = MaxCycle;
		bool CatchValue = false;
		auto IterX = ElementList.begin();
		auto IterCurrentValue = ElementList.begin();
		while (IterX != ElementList.end() )
		{   
			std::cout << "Now IterX.first - " << (*IterX).first << " and IterX.second - " << (*IterX).second << std::endl;
		    if ( (*IterX).first == i and (*IterX).second < Vsecond ) 
		    {
		    	std::cout << "Stage 1 Enter " << std::endl;
		    	Vsecond = (*IterX).second;
		    	std::cout << "Vsecond now - " << Vsecond << std::endl;
		    	IterCurrentValue = IterX;
		    	CatchValue = true;
				IterX++; 
			}
		    else if ( (*IterX).first == i and (*IterX).second >= Vsecond ) 
			{
				std::cout << "Stage 2 Enter " << std::endl;
				IterX++;
			}
			else if ( (*IterX).first != i )
			{
				std::cout << "Stage 3 Enter " << std::endl;
				IterX++;
			}
			
			if ( IterX == ElementList.end() ) std::cout << "ElementList.end() reached for i = " << i << std::endl; 
		}
		if (CatchValue)
		{
			std::cout << "Entering copying stage. Copying - " << (*IterCurrentValue).first << " and " << (*IterCurrentValue).second << ". Vsecond = " << Vsecond << " and i = " << Vsecond+1 << std::endl;
			ElementX.first = (*IterCurrentValue).first;
			ElementX.second = (*IterCurrentValue).second;
			ElementListFinal.push_back(ElementX);
			i = Vsecond+1; 
		}
		else
		{
			i++;
			std::cout << "Alter stage. Now i = " << i << std::endl;	
		}
		if ( i >= MaxCycle ) break;
	}
*/	

//============CODE2=======================================================
for (size_t i = 1; i<MaxCycle;)
	{
		std::cout << std::endl;     // Trassing
		std::cout << "**********  Now i - " << i << "  **********"<< std::endl;     // Trassing
		int Vsecond = MaxCycle;
		bool CatchValue = false;
		bool IterCurrentValueUsed = false;
		auto IterX = ElementList.begin();
		auto IterCurrentValue = ElementList.begin();
		while (IterX != ElementList.end() )
		{   
			std::cout << "Now IterX.first - " << (*IterX).first << " and IterX.second - " << (*IterX).second << std::endl;
		    if ( (*IterX).first == i and (*IterX).second < Vsecond ) 
		    {
		    	std::cout << "Stage 1 Enter " << std::endl;
		    	Vsecond = (*IterX).second;
		    	std::cout << "Vsecond now - " << Vsecond << std::endl;
		    	if (IterCurrentValueUsed)
		    	{
		    		ElementList.erase(IterCurrentValue);
		    		IterCurrentValue = IterX;
					IterCurrentValueUsed = true;
				}
				else
				{
					IterCurrentValue = IterX;
					IterCurrentValueUsed = true;	
				}
				IterX++;
		    	CatchValue = true; 
			}
		    else if ( (*IterX).first == i and (*IterX).second >= Vsecond ) 
			{
				std::cout << "Stage 2 Enter. Erase element IterX.first - " << (*IterX).first << " and IterX.second - " << (*IterX).second << std::endl;
				IterX = ElementList.erase(IterX);
			}
			else if ( (*IterX).first != i )
			{
				std::cout << "Stage 3 Enter " << std::endl;
				IterX++;
			}
			
			if ( IterX == ElementList.end() ) std::cout << "ElementList.end() reached for i = " << i << std::endl; 
		}
		if (CatchValue)
		{
			std::cout << "Vsecond = " << Vsecond << " and i = " << Vsecond+1 << std::endl;
			i = Vsecond+1; 
		}
		else
		{
			i++;
			std::cout << "Alter stage. Now i = " << i << std::endl;	
		}
		
		if ( i >= MaxCycle ) break;
	}
//========================================================================











/*
//========================New Block========================================
	
	for (size_t i = 1; i<MaxCycle; i++)
	{
		std::cout << std::endl;     // Trassing
		std::cout << "**********  Now i - " << i << "  **********"<< std::endl;     // Trassing
		auto IterX = ElementList.begin();
		while (IterX != ElementList.end() )
		{
			int Vfirst = (*IterX).first;
		    int Vsecond = (*IterX).second;

			std::cout << "Int first = " << Vfirst << " and Int second = " << Vsecond << std::endl;  // Trassing
			std::cout << "=========Stage " << i << " start======================" << std::endl;     // Trassing
			if  ( Vfirst != i and Vfirst != 4 ) 
			{
				std::cout << "Current Iter value - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
				std::cout << "Not found i - " << i << " in .first pair < " << (*IterX).first << "," << (*IterX).second << " >" <<std::endl;     // Trassing
				IterX++;
				std::cout << "Next i is - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
			}
		
			if  (Vfirst == i and Vfirst != 4) 
			{
				std::cout << "Current Iter value - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
				std::cout << "Found i - " << i << " in .first pair < " << (*IterX).first << "," << (*IterX).second << " >" <<std::endl;     // Trassing
//				if (IterX != --ElementList.end() ) IterX++;
				IterX++;
				std::cout << "Next i is - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
			}
			
			if  ( Vfirst == 4) 
			{
				std::cout << "Current Iter value - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
				std::cout << "Found 4 !!! - " << i << " in .first pair < " << (*IterX).first << "," << (*IterX).second << " >" <<std::endl;     // Trassing
				IterX = ElementList.erase(IterX);
				std::cout << "Next i is - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
			}
			
			if (IterX == ElementList.end()) 
			{
				std::cout << " ElementList.end() reached " << std::endl;     // Trassing
			}
			
			std::cout << "=========Stage " << i << " ende======================" << std::endl;     // Trassing
					system("pause");
		}
		std::cout << "Cycle " << i << " is end" << std::endl;   // Trassing
		system("pause");
	}

//=========================================================================


//======================================1 start================================================================

	for (size_t i = 1; i<MaxCycle; i++)
	{
		std::cout << std::endl;     // Trassing
		std::cout << "**********  Now i - " << i << "  **********"<< std::endl;     // Trassing
		auto IterX = ElementList.begin();
		auto IterCurrentValue = ElementList.begin();
		while (IterX != ElementList.end() )
		{
			int Vfirst = (*IterX).first;
		    int Vsecond = (*IterX).second;

			std::cout << "Int first = " << Vfirst << " and Int second = " << Vsecond << std::endl;  // Trassing
			std::cout << "=========Stage " << i << " start======================" << std::endl;     // Trassing
			if  ( Vfirst != i ) IterX++;
		
			if  ( Vfirst == i ) 
			{
				if ( (*IterCurrentValue).first != i ) 
				{
					IterCurrentValue = IterX; 
					IterX++;
				}
				else
				{
					if ( Vsecond < (*IterCurrentValue).second )
				}
				std::cout << "Next i is - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
			}
			
			if  ( Vfirst == 4) 
			{
				std::cout << "Current Iter value - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
				std::cout << "Found 4 !!! - " << i << " in .first pair < " << (*IterX).first << "," << (*IterX).second << " >" <<std::endl;     // Trassing
				IterX = ElementList.erase(IterX);
				std::cout << "Next i is - " << (*IterX).first << "," << (*IterX).second << std::endl;     // Trassing
			}
			
			if (IterX == ElementList.end()) 
			{
				std::cout << " ElementList.end() reached " << std::endl;     // Trassing
			}
			
			std::cout << "=========Stage " << i << " ende======================" << std::endl;     // Trassing
					system("pause");
		}
		std::cout << "Cycle " << i << " is end" << std::endl;   // Trassing
		system("pause");
	}
	
//======================================1 ende================================================================
*/
	
    std::cout << std::endl;
    std::cout << ElementList.size() << std::endl;
    std::cout << "Result is : " << std::endl;
	for (std::pair<int, int> ValX : ElementList)
	{
		std::cout << ValX.first << "  " << ValX.second << std::endl;
	}
	
	return 0;
}