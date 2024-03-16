#include <iostream>
#include <string>
#include <vector>

int main ()
{
	
/*	
	bool LengthSucess(false);
	unsigned int SymbolRangeSucess = 0;
	bool BigSymbolSucess(false);
	bool SmallSymbolSucess(false);
	bool NuberSymbolSucess(false);
	bool OtherSymbolSucess(false);
	int SymbolClassOK = 0;
	
	std::string PassX;
	std::cin >> PassX;
	
	if ( PassX.size()>=8 && PassX.size()<=14 ) LengthSucess = true;
	
	for (unsigned int i=0; i<PassX.size(); i++)
	{
		int TempChar = static_cast<int>(PassX[i]);
		if ( (TempChar>=33) && (TempChar<=126) ) SymbolRangeSucess++ ;
		if ( (TempChar>=48) && (TempChar<=57) ) NuberSymbolSucess = true;
		if ( (TempChar>=65) && (TempChar<=90) ) BigSymbolSucess = true;
		if ( (TempChar>=97) && (TempChar<=122) ) SmallSymbolSucess = true;
        if ( (TempChar>=33 && TempChar<=47) || (TempChar>=58 && TempChar<=64) || (TempChar>=91 && TempChar<=96) ) OtherSymbolSucess = true;		
	}
	
	SymbolClassOK = static_cast<int>(NuberSymbolSucess) + static_cast<int>(BigSymbolSucess) + static_cast<int>(SmallSymbolSucess) + static_cast<int>(OtherSymbolSucess);

	if ( SymbolClassOK >=3 && SymbolRangeSucess == PassX.size() && LengthSucess) std::cout << "YES";
	else  std::cout << "NO";
*/
 
/* 
    std::string WordX;
    while (1)
	{
		std::cin >> WordX;
		bool CharOK = false;
		for (unsigned int i= 0; i<WordX.size(); i++ )
		{   
		    char TestChar = static_cast<int>(WordX[i]);
			if ( (TestChar>=97) && (TestChar<=122) ) CharOK = true;
			else 
			{
				CharOK = false;
				break;
			}
		}
		if ( CharOK && WordX.size()<=20 ) break;
    }
    
    std::string SoundexWord;
    
    SoundexWord = SoundexWord + WordX[0];
    
    for (unsigned int i=1; i < WordX.size(); i++)
    {
        char TempCharX = '0';
        unsigned int SoundexWordSize = SoundexWord.size();
    	if ( WordX[i] == 'b' || WordX[i] == 'f' ||  WordX[i] == 'p' || WordX[i] == 'v' ) TempCharX = '1'; 
    	if ( WordX[i] == 'c' || WordX[i] == 'g' ||  WordX[i] == 'j' || WordX[i] == 'k' ||  WordX[i] == 'q' ||  WordX[i] == 's' ||  WordX[i] == 'x' ||  WordX[i] == 'z') TempCharX = '2';
    	if ( WordX[i] == 'd' || WordX[i] == 't' ) TempCharX = '3';
    	if ( WordX[i] == 'l' ) TempCharX = '4';
    	if ( WordX[i] == 'm' || WordX[i] == 'n' ) TempCharX = '5';
    	if ( WordX[i] == 'r' ) TempCharX = '6';
        
		if ( SoundexWord[SoundexWordSize-1] != TempCharX && TempCharX != '0' )  SoundexWord = SoundexWord + TempCharX;
	}
	
	if ( SoundexWord.size() < 4 )
	{
		for (unsigned int i=SoundexWord.size(); i < 4; i++)  SoundexWord = SoundexWord + '0';    	
	}
	else SoundexWord.resize(4);
	std::cout << SoundexWord;
*/
    
    unsigned int GuestNumber;
    std::cin >> GuestNumber;
    std::vector<int>GuestVector(GuestNumber);
    
    
    for (unsigned int i=0; i<GuestNumber; i++)
    { 
        int tempV;
    	std::cin >> tempV;
        GuestVector[i] = tempV;
    }
    
	for (auto elementX : GuestVector)
    {
    	std::cout << elementX << " ";
    }
    std::cout << std::endl;
    
	return 0;
}
