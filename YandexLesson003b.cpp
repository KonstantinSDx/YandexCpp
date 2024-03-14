#include <iostream>
#include <cmath>

int main()
{
/*
   int CurrentWeekPosition;
   int DayInMonth;
   int WeekDay=1;
   std::cin >> CurrentWeekPosition;	
   std::cin >> DayInMonth;
   
   while ( WeekDay < CurrentWeekPosition )
	{
		std::cout << "   ";
		WeekDay++;
	}
		
	for (int i=1; i<=DayInMonth; i++)
	{   
	    if (i<10) std::cout  << " " << i;
	    else std::cout << i;
		if ( WeekDay%7 == 0 ) std::cout << std::endl;
		else std::cout << " ";
		WeekDay++;	
	}
    std::cout << std::endl;	
*/

/*
    int degree = 9;
    unsigned int NumberX;
	int Summ = 0;
	std::cin >> NumberX;
   while (degree >= 0)
   {
   	  int TempVal;
   	  TempVal = NumberX / powl(10, degree);
	  Summ = Summ + TempVal;
   	  NumberX = NumberX - TempVal*powl(10, degree);
	  degree--;
   }
   std::cout << Summ; 
   
*/ 
   double Result = 0;
   int NubmberLn;
   std::cin >> NubmberLn;
   
   for ( int i=1; i <=NubmberLn ; i++)
   {
   	  Result = Result + powl(-1, i+1)/i; 
   } 
   std::cout << Result; 
	return 0;
}
