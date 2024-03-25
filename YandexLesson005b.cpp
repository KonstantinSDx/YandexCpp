#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

/*
std::string Join(const std::vector<std::string>& tokens, char delimiter)
{
	std::string ReturnString;
	if ( tokens.empty() ) return ReturnString;
	if ( tokens.size()==1 ) return ReturnString.assign(tokens[0]);  
	else
	{
		for (unsigned int i=0; i<tokens.size(); i++)
		{
			if ( i == (tokens.size()-1) ) ReturnString = ReturnString + tokens[i];
			else ReturnString = ReturnString + tokens[i] + delimiter;
		}
	}
	return ReturnString;
}
*/

/*
std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix)
{
	int ReturnVectorRow = matrix[0].size();
	int ReturnVectorColumn = matrix.size();
	std::vector<std::vector<int>> ReturnTransponentMatrix( ReturnVectorRow, std::vector<int>(ReturnVectorColumn) );
	std::vector<int> TempColumn;
	for (unsigned int i=0; i<ReturnTransponentMatrix.size(); i++)
	{
		TempColumn = matrix[i];
		for (unsigned int j=0; j<ReturnTransponentMatrix[i].size(); j++)
		{
			ReturnTransponentMatrix[j][i] = TempColumn[j];
		}
	}
	return ReturnTransponentMatrix;
}
*/

/*
std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix)
{
	unsigned int ReturnVectorRow = matrix[0].size();
	unsigned int ReturnVectorColumn = matrix.size();
	std::vector<std::vector<int>> ReturnTransponentMatrix( ReturnVectorRow, std::vector<int>(ReturnVectorColumn) );
	for (unsigned int i=0; i<ReturnVectorColumn; i++)
	{
		for (unsigned int j=0; j<ReturnVectorRow; j++)
		{
			ReturnTransponentMatrix[j][i] = matrix[i][j];
		}
	}
	return ReturnTransponentMatrix;
}
*/

bool PointSort ( const std::pair<int, int> &ValueOne, const std::pair<int, int> &ValueTwo)
{
	int Value1 = ValueOne.first*ValueOne.first + ValueOne.second*ValueOne.second;
	int Value2 = ValueTwo.first*ValueTwo.first + ValueTwo.second*ValueTwo.second;
	return ( sqrt(Value1) < sqrt(Value2) );	
}



int main ()
{
    int NumbersOfPoint;
    std::cin >> NumbersOfPoint;
	std::vector<std::pair<int, int>>PointVector(NumbersOfPoint);
    
    for (unsigned int i=0; i<NumbersOfPoint; i++)
    {
    	std::cin >> PointVector[i].first >> PointVector[i].second;
    } 
	 
    std::sort ( begin(PointVector), end(PointVector), PointSort );
    
    for (unsigned int i=0; i<NumbersOfPoint; i++)
    {
    	std::cout << PointVector[i].first << " " << PointVector[i].second << std::endl;
    }
     
/*	
	int VectorRow;
	int VectorColumn;
	std::cout << "Enter Vector Row - m : ";
	std::cin >> VectorRow;
	std::cout << "Enter Vector Column - n : ";
	std::cin >> VectorColumn;
	std::vector<std::vector<int>>MatrixVector( VectorRow, std::vector<int>(VectorColumn) );
	std::vector<std::vector<int>>ResultVector;
	
	for (unsigned int i=0; i<MatrixVector.size(); i++)
	{
		std::cout << "Enter " << i << " Row : ";
		for (unsigned int j=0; j<MatrixVector[0].size(); j++)  std::cin >> MatrixVector[i][j];
	}
	
	std:: cout << "Base Matrix :" << std::endl;
	for (unsigned int i=0; i<MatrixVector.size(); i++)
	{
		for (unsigned int j=0; j<MatrixVector[0].size(); j++)  
		{	
		   if ( j < MatrixVector[0].size()-1 ) std::cout << MatrixVector[i][j] << " ";
		   else std::cout << MatrixVector[i][j];
	    }
	    std::cout << std::endl;
	}
	
	ResultVector = Transpose(MatrixVector); 
	
	std::cout << std::endl;
	std:: cout << "Transponent Matrix :" << std::endl;
	for (unsigned int i=0; i<ResultVector.size(); i++)
	{
		for (unsigned int j=0; j<ResultVector[0].size(); j++)  
		{	
		   if ( j < ResultVector[0].size()-1 ) std::cout << ResultVector[i][j] << " ";
		   else std::cout << ResultVector[i][j];
	    }
	    std::cout << std::endl;
	}
*/
	
/*	
	std::vector<std::string>StringVector;
	std::string TempString;
	char delimiterX;
	
	while(true)
	{
		std::getline (std::cin, TempString);
		if ( TempString.empty() ) 
		{
		   std::cout << std::endl;
		   std::cout << "Add String Ende" << std::endl; 
		   break;	
		}
		else StringVector.push_back(TempString);
	}
	std::cout << "Enter delimiter : ";
	std::cin >> delimiterX;
	
	std::cout << Join(StringVector, delimiterX);
*/	
	return 0;
}
