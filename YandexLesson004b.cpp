#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>


int main ()
{
/*
	std::vector<std::string> StrVector;
	std::string StrX;
	
	while (true)
	{
		std::getline (std::cin, StrX);
		StrVector.push_back(StrX);
		if (StrX == "three") break;
	}
	
//	for (int i=0; i<StrVector.size(); i++)
//	{
//		std::getline (std::cin, StrX);
//		StrVector[i] = StrX;
//	}

	
	unsigned int VectorLength = StrVector.size();
	for (unsigned int j = 0; j < VectorLength; VectorLength-- )
	{
		for (unsigned int f = 0; f < VectorLength-1; f++ )
		{
			if ( StrVector[f]<StrVector[f+1])  swap (StrVector[f],StrVector[f+1]);
		}
		
	}
	
	for ( auto ElementX : StrVector )
	{
		std::cout << ElementX << std::endl;
	}
*/

/*
    std::string LineX;
    std::getline(std::cin, LineX);
    bool ItsPalindrom = false;
    
    if (LineX.size() == 0)
    {
       ItsPalindrom = true;
    }
    else
	{	
    	for ( unsigned int i=0, j=LineX.size()-1 ; i<j; )
    	{
    	
    		while(1)
    		{
    			if (static_cast<int>(LineX[i])== 32) i++;
    			else break;
    		}
        
			while(1)
    		{
    			if (static_cast<int>(LineX[j])== 32) j--;
    			else break;
    		}
    	
			if (LineX[i] == LineX[j]) 
			{
			    ItsPalindrom = true;
			    i++; 
			    j--;		
			}
			else 
			{
			    ItsPalindrom = false;	
			    break;
			} 
    	}
	}	    
    
    if (ItsPalindrom==true) std::cout << "YES";
    else  std::cout << "NO";
*/


    int RowS;
    int ColumnS;
    int MineS;
    
    std::cin >> RowS;
    std::cin >> ColumnS;
    std::cin >> MineS;
    RowS = RowS + 2;
    ColumnS = ColumnS + 2;
    unsigned int MineXTemp;
    unsigned int MineYTemp;
    std::vector< std::vector<int>> MineField(RowS, std::vector<int>(ColumnS));
    for (int i=0; i<RowS; i++)
    {
    	for (int j=0; j<ColumnS; j++)  MineField[i][j] = 48;
    }
    
    for (int i = 0; i<MineS; i++)
    {
    	std::cin >> MineXTemp;
		std::cin >> MineYTemp;
		MineField[MineXTemp][MineYTemp] = 42;
    }
    
    
    
    for (int i=1; i<RowS-1; i++)
    {
    	for (int j=1; j<ColumnS-1; j++)
    	{
    		if(MineField[i][j]==42)
    		{
    			if ( MineField[i-1][j-1] != 42)  MineField[i-1][j-1] = MineField[i-1][j-1] + 1; 
    			if ( MineField[i][j-1] != 42)   MineField[i][j-1] = MineField[i][j-1] + 1;
    			if ( MineField[i+1][j-1] != 42)  MineField[i+1][j-1] = MineField[i+1][j-1] + 1;
    			if ( MineField[i-1][j] != 42)  MineField[i-1][j] = MineField[i-1][j] + 1;
    			if ( MineField[i+1][j] != 42)  MineField[i+1][j] = MineField[i+1][j] + 1;
    			if ( MineField[i-1][j+1] != 42)  MineField[i-1][j+1] = MineField[i-1][j+1] + 1;
    			if ( MineField[i][j+1] != 42)  MineField[i][j+1] = MineField[i][j+1] + 1;
    			if ( MineField[i+1][j+1] != 42)  MineField[i+1][j+1] = MineField[i+1][j+1] + 1;	
    		}
    	}
    }
    
    for (int i=1; i<RowS-1; i++)
    {
    	for (int j=1; j<ColumnS-1; j++)   std::cout << static_cast<char>(MineField[i][j]) << " ";
    	std::cout << std::endl;
    }

/*
    std::mt19937 mersenne( time(0) );
    std::vector<int> NumberArr;
    for (int i =0; i<3; i++)
    {
    	int Num1 = ( mersenne()& 0b11111111000000000000000000000000 ) >> 24; 
    	int Num2 = ( mersenne()& 0b00000000111111110000000000000000 ) >> 16;
    	int Num3 = ( mersenne()& 0b00000000000000001111111100000000 ) >> 8;
    	int Num4 = mersenne()& 0b00000000000000000000000011111111 ;
    	NumberArr.push_back(Num1);
    	NumberArr.push_back(Num2);
    	NumberArr.push_back(Num3);
    	NumberArr.push_back(Num4);
    }
    
    for (int i = 0; i < NumberArr.size(); i++)
    {
    	if ( i%6 != 0 )  std::cout << NumberArr[i] << " ";
    	else 
    	{
    		std::cout << std::endl;
    		std::cout << NumberArr[i] << " ";
    	}
    	
    }
    
    std::vector<char> CharArr;
    for (int i =0; i<65536; i++)
    {
    	int Char1 = ( mersenne()& 0b01111111000000000000000000000000 ) >> 24; 
    	int Char2 = ( mersenne()& 0b00000000011111110000000000000000 ) >> 16;
    	int Char3 = ( mersenne()& 0b00000000000000000111111100000000 ) >> 8;
    	int Char4 = mersenne()& 0b00000000000000000000000001111111 ;
    	CharArr.push_back( static_cast<char>(Char1) );
    	CharArr.push_back( static_cast<char>(Char2) );
    	CharArr.push_back( static_cast<char>(Char3) );
    	CharArr.push_back( static_cast<char>(Char4) );
    }
    
    std::cout << std::endl;
    std::cout << "===============================================\n";
    std::cout << "=============With Ptr==========================\n";
	int *Ptr_int = &NumberArr[0];
	
	for (int i = 0; i < NumberArr.size(); i++)
    {
    	if ( i%6 != 0 )  std::cout << *(Ptr_int+i) << " ";
    	else 
    	{
    		std::cout << std::endl;
    		std::cout << *(Ptr_int+i) << " ";
    	}
    	
    }
	
	std::cout << std::endl;
    std::cout << "===============================================\n";
    std::cout << "=============Resize Array==========================\n";
	
	    
    for (int i =0; i<1024; i++)
    {
    	int Num1 = ( mersenne()& 0b11111111000000000000000000000000 ) >> 24; 
    	int Num2 = ( mersenne()& 0b00000000111111110000000000000000 ) >> 16;
    	int Num3 = ( mersenne()& 0b00000000000000001111111100000000 ) >> 8;
    	int Num4 = mersenne()& 0b00000000000000000000000011111111 ;
    	NumberArr.push_back(Num1);
    	NumberArr.push_back(Num2);
    	NumberArr.push_back(Num3);
    	NumberArr.push_back(Num4);
    }
    
    for (int i = 0; i < 12; i++)
    {
    	if ( i%6 != 0 )  std::cout << *(Ptr_int+i) << " ";
    	else 
    	{
    		std::cout << std::endl;
    		std::cout << *(Ptr_int+i) << " ";
    	}
    	
    }

*/
    return 0;
	
			
}
