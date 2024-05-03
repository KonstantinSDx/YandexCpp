#include <iostream>
#include <set>
#include <string>
#include <list>
#include <vector>

int main()
{
	

	std::string Command;
	int AddValue;
	bool CyCleON = true;
	std::multiset<int>ValueMultiset;
	while ( CyCleON )
	{
		std::cin >> Command;
		if (Command == "ADD")
		{
			std::cin >> AddValue;
			ValueMultiset.insert(AddValue);
			AddValue = 0;
		}
		else if (Command == "EXTRACT")
		{
			if (!ValueMultiset.empty())
			{
				std::cout << *(--ValueMultiset.end()) << std::endl;
				ValueMultiset.erase(--ValueMultiset.end());	
		    }
		    else std::cout << "CANNOT" << std::endl;
		}
		else if (Command == "CLEAR")
		{
			ValueMultiset.clear();
		}
		else if (Command == "\r\n") CyCleON = false;
	}


/*
	int n;
	int k;
	std::list<int>MyListX;
	while (true)
	{
		std::cin >> n >> k;
		if ( (n <= 150000)&&(k<=10000)&&(k<=n) ) break;
	}	
	
	std::vector<int>ResultVector(1);
	std::multiset<int>SetX;
	int ListValue;
	for ( unsigned int i=0; i<n; i++)
	{
		std::cin >> ListValue; 
		if ( MyListX.size()<k ) 
		{
			MyListX.emplace_back(ListValue);
		}
		if ( MyListX.size()==k ) 
		{
			
			std::cout << "Now List is - ";
			for (int ValX : MyListX)
			{
				std::cout << ValX << " ";
			}
			std::cout << std::endl;
			
			for (int ValX : MyListX)
			{
				SetX.insert(ValX);
			}
			std::cout << *(SetX.begin());
			SetX.clear();
			MyListX.erase(MyListX.begin());
			
			std::cout << "Now Correct List is - ";
			for (int ValX : MyListX)
			{
				std::cout << ValX << " ";
			}
			std::cout << std::endl;
		}
	}
	
	
//	for (int i=1; i<ResultVector.size(); i++ )
//	{
//		std::cout << ResultVector[i] << std::endl;
//	}
*/


/*	
	int n;
	int k;
	while (true)
	{
		std::cin >> n >> k;
		if ( (n <= 150000)&&(k<=10000)&&(k<=n) ) break;
	}	
	std::multiset<int>SetX;
	int IntVectorX[n];
	for ( unsigned int i=0; i<n; i++)
	{
		std::cin >> IntVectorX[i];
	}
	
	for (unsigned int i =0; (k+i)<n+1 ; i++)
	{	
	    SetX.clear();
		for (unsigned int j=i; j<i+k; j++)
		{
           SetX.insert(IntVectorX[j]);
		}
		std::cout << *(SetX.begin()) << std::endl; 
	}
*/	
	
	
	
/*	
    int n;
	int k;
	while (true)
	{
		std::cin >> n >> k;
		if ( (n <= 150000)&&(k<=10000)&&(k<=n) ) break;
	}	
	
	std::vector<int>IntVectorX(n, 0);
	for ( unsigned int i=0; i<n; i++)
	{
		std::cin >> IntVectorX[i];
	}
	
	for (unsigned int i =0; (k+i)<n+1 ; i++)
	{
		int MinInt = IntVectorX[i];
		
		for (unsigned int j=i; j<i+k-1; j++)
		{
			if ( MinInt > IntVectorX[j+1]) 
			{
			   MinInt = IntVectorX[j+1];	
			}
		}
		std::cout << MinInt << std::endl; 
	}
*/	


/*
	std::string StringLine;
	std::getline(std::cin, StringLine);
	std::stack<int>MyStackX;
	char LastElement;
	bool YesNo = false;
    for (unsigned int i=0; i<StringLine.size(); i++)
	{
		
		if ( i==0 && ( StringLine[i] == '}' || StringLine[i] == ']' || StringLine[i] == ')' ) )
		{
			MyStackX.push( StringLine[i] );
		    break;	
		}
		
		if ( StringLine[i] == '{' || StringLine[i] == '[' || StringLine[i] == '(' )
		{
			LastElement = StringLine[i];
			MyStackX.push( StringLine[i] );
			std::cout << "Now StringLine[i] = " << StringLine[i] << " push in stack. Stack size is - " << MyStackX.size() << std::endl; 
		}
		
		if ( i !=0 && ( StringLine[i] == '}' || StringLine[i] == ']' || StringLine[i] == ')' ) )
		{
			if (  (LastElement == '{' && StringLine[i] == '}') || (LastElement == '(' && StringLine[i] == ')') || (LastElement == '[' && StringLine[i] == ']') )
			{
				MyStackX.pop();
				if ( MyStackX.empty() ) LastElement = '0';
				else LastElement = MyStackX.top();
				  	
				std::cout << "Now StringLine[i] = " << StringLine[i] << " POP stack. Stack size is - " << MyStackX.size() << ". LastElement is - " << LastElement << std::endl; 
			}
            else break;
		} 
	}

    if ( MyStackX.empty() && !StringLine.empty() ) YesNo = true;
   	if ( YesNo ) std::cout << "YES";
	else  std::cout << "NO";
*/

	return 0;
}
