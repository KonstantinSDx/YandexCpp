#include <iostream>
#include <set>
#include <string>
#include <cstdint>


/*
class RGBA
{
  	std::uint8_t m_red;
  	std::uint8_t m_green;
  	std::uint8_t m_blue;
  	std::uint8_t m_alpha;
  	
  	public:
	RGBA ( std::uint8_t Red = 0, std::uint8_t Green = 0, std::uint8_t Blue = 0, std::uint8_t Alpha = 255) : m_red(Red), m_green(Green), m_blue(Blue), m_alpha(Alpha)
    {
		  	
    } 
   		  
    void print()
    {
    	 std::cout << "r=" << static_cast<int>(m_red) << " " << "g=" << static_cast<int>(m_green) << " " << "b=" << static_cast<int>(m_blue) << " " << "a=" << static_cast<int>(m_alpha);	   	
    }		  	
};
*/



int main ()
{
	
/*
	std::set<int> MySetX;
	int TempVal;
	while(std::cin >> TempVal)
	{
		if ( MySetX.find(TempVal)== MySetX.end() ) 
		{
		   MySetX.insert(TempVal);
		   std::cout << "NO" << std::endl;	
		}
		else std::cout << "YES" << std::endl;
		if ( TempVal == 0 ) break;
    }
*/

    
/*  
    std::set<char> TempCharSet; 
    std::multiset<char> CharMultiset;
	std::string WordX;
	unsigned int NumbersOfWord = 5;  
    for (unsigned int i = 0; i< NumbersOfWord; i++)
    {
    	std::cin >> WordX;
    	for (unsigned int j = 0; j<WordX.size() ; j++)
    	{
    		TempCharSet.insert(WordX[j]);
    	}
        
    	for (char TempCharSetValue : TempCharSet)
    	{
    		CharMultiset.insert(TempCharSetValue);
    	}
    	TempCharSet.clear();
    } 

    TempCharSet.clear(); 
    for ( unsigned int i = 97; i<123; i++)
    {
    	unsigned int NumberOfChar;
    	NumberOfChar = CharMultiset.count( static_cast<char>(i));
    	if (NumberOfChar == NumbersOfWord) TempCharSet.insert( static_cast<char>(i)); 
    }
    
    for (char CharSetX : TempCharSet)
    {
    	std::cout << CharSetX;
    }
*/

/*
    RGBA color(0, 135, 135);
	color.print();
*/
   
    
return 0;	
}
