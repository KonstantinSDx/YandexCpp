#include <iostream>
#include <cmath>

int main()
{
/*	
============Chess 1========================================	
	int x1, y1;
	int x2, y2;
	std::cin >> x1;
	std::cin >> y1;
	std::cin >> x2;
	std::cin >> y2;
	
	if ( (x1==x2) || (y1==y2) ) 
	{
		std::cout << "YES";
	} 
	else if ( abs(x1-x2) == abs(y1-y2) )
	{
		std::cout << "YES";
	}
	else  std::cout << "NO";
===========================================================
*/

/*	
============Trangles 1========================================	
int a, b, c;

std::cin >> a;
std::cin >> b;
std::cin >> c;

if ( ((a+b)<=c) || ((a+c)<=b) || ((b+c)<=a) )
{
	std::cout << "UNDEFINED";
}
else if (  (a*a == b*b + c*c) || ( b*b == a*a + c*c) || ( c*c == a*a + b*b) ) 
{
	std::cout << "YES";
}
else
{
	std::cout << "NO";
}
===========================================================
*/

/*	
============Year 1========================================	

unsigned int YearX;
std::cin >> YearX;
if ( YearX%400 == 0 )
{
	std::cout << "YES";
}
else if ( ( YearX%4 == 0 ) && !(YearX%100 == 0) )
{
	std::cout << "YES";	
}
else 
{
	std::cout << "NO";	
}
===========================================================
*/
unsigned int MonthX;
unsigned int YearX;
bool LeapYear = false;
std::cin >> MonthX;
std::cin >> YearX;
if ( YearX%400 == 0 )  LeapYear = true;
if ( ( YearX%4 == 0 ) && !(YearX%100 == 0) ) LeapYear = true;	

switch (MonthX)
{
	case 1 :  std::cout << "31";
		      break;
	case 2 :  if (LeapYear) std::cout << "29"; 
		      else  std::cout << "28";
		      break;
	case 3 :  std::cout << "31";
		      break;
	case 4 :  std::cout << "30";
		      break;		
    case 5 :  std::cout << "31";
		      break;
    case 6 :  std::cout << "30";
		      break;
    case 7 :  std::cout << "31";
		      break;
    case 8 :  std::cout << "31";
		      break;
    case 9 :  std::cout << "30";
		      break;
	case 10 : std::cout << "31";
		      break;
	case 11 : std::cout << "30";
		      break;
	case 12 : std::cout << "31";
		      break;	
}
	
return 0;
}
