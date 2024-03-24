#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> Split(const std::string& str, char delimiter)
{
	std::string TempStr;
	std::string ZeroStr;
	std::vector<std::string>TempVect;
	if ( str.empty() ) return TempVect;
	for (unsigned int i = 0; i<str.size(); i++)
	{
		if ( str[i]==delimiter && TempStr.empty() ) TempVect.push_back(ZeroStr);
		
		if ( str[i]==delimiter && !TempStr.empty() ) 
		{
		   TempVect.push_back(TempStr);
		   TempStr.clear();	
		}
		
		if ( str[i]!=delimiter ) TempStr = TempStr + str[i];
		if ( i==(str.size()-1) && str[i] == delimiter) TempVect.push_back(ZeroStr);
		if ( i==(str.size()-1) && !TempStr.empty() ) TempVect.push_back(TempStr);
	}
	return TempVect;
}




/*
std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix)
{
	int YAxis = matrix.size();
	int XAxis = matrix[0].size();
	std::pair<int, int>MaxElementIndex; 
	int MaxElementValue = matrix[0][0];
	
	for (int i = 0; i<YAxis; i++)
	{
		for (int j = 0; j<XAxis; j++)
		{
			if ( matrix[i][j] > MaxElementValue )
			{
			    MaxElementValue = matrix[i][j];
				MaxElementIndex.first = i;
				MaxElementIndex	.second = j;
			}
		}
	}
	return MaxElementIndex;
}
*/


/*
std::string CommonPrefix(const std::vector<std::string>& words)
{
	std::string CurrentPrefix;
	if ( words.empty() ) return CurrentPrefix; 
	unsigned int MinStringLength = words[0].size();
	for (unsigned int i=1; i<words.size(); i++)
	{
	   	if ( MinStringLength>words[i].size() )  MinStringLength = words[i].size();
	}
		
	unsigned int IndexVector = 0;
	unsigned int IndexString = 0;
	bool CycleOn = true;
	while (CycleOn)
	{
	   char CharNext = words[IndexVector][IndexString];
	   
	   for ( ; IndexVector < words.size(); IndexVector++)
	   {
            if ( CharNext!=words[IndexVector][IndexString] ) CycleOn = false; 	   	
	   }
	   IndexVector = 0;
	   IndexString++;
	   if (CycleOn) CurrentPrefix = CurrentPrefix + CharNext;
	   if ( IndexString == (MinStringLength - 1) ) CycleOn = false;
	}
	return CurrentPrefix;
}
*/

int main ()
{

    std::string StringX;
	char DelimiterX;
	std::vector<std::string>ResultVec;
	
	std::getline(std::cin, StringX);
	std::cin >> DelimiterX;
	
    ResultVec = Split(StringX, DelimiterX);
	for (std::string Str1 : ResultVec)
    {
    	std::cout << Str1 << std::endl;
    } 

/*
	std::vector<std::string>Str_Vector;
	std::string StringX;
	while(true)
	{
	   std::getline(std::cin, StringX);
	   if ( StringX.empty() ) break;
	   else 
	   {
	   	  Str_Vector.push_back(StringX);
	   	  StringX.clear(); 
	   }	
	}
	
	std::cout << std::endl;
	std::cout << CommonPrefix(Str_Vector);
	 
		
	int YLine;
	int XLine;
    std::cin >> YLine;
	std::cin >> XLine;
	std::vector<std::vector<int>> Array1(YLine, std::vector<int>(XLine));
	
	for (int i = 0; i<YLine; i++)
	{
		for (int j = 0; j<XLine; j++)
		{
			std::cin >> Array1[i][j];
		}
	}
    std::pair<int,int>Result1;
	Result1 = MatrixArgMax(Array1);
	std::cout << Result1.first << " " << Result1.second;
*/
   


	return 0;
}
