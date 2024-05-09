#include <iostream>
#include <cassert>

class Calendar
{
	private:
	int m_Day;
	int m_Month;
	int m_Year;
				
	public:
	const int LeapYear[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int OrdinaryYear[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   	const int LeapYearMonthSumm[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	const int OrdinaryYearMonthSumm[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};	
	Calendar(int day, int month, int year)
	{
		if ( ( day>=1 && day<32 ) && ( month>=1 && month<13 ) && ( year>=1970 && year<2100 ) )
		{
			m_Day = day;
	        m_Month = month;
	        m_Year = year;
		}
		else 
		{
			m_Day = 1;
	        m_Month = 1;
	        m_Year = 1970;
		}
	}
	
    int GetDay() const { return m_Day; } 
	int GetMonth() const { return m_Month; } 
	int GetYear() const { return m_Year; }
    
	Calendar& operator+ (int dayS)
	{
		while (dayS !=0)
		{
			std::cout << "Cycle on" << std::endl; // Trassing
			assert ( ( dayS >= 0 ) && "Error - dayS < 0 and cycle not ended" );
			if ( ( m_Year%4==0 )&&( m_Year%100!=0 )||( m_Year%400==0 ) )
			{
			    if ( dayS > LeapYear[m_Month]-m_Day )
				{
					if ( m_Month == 12) 
					{
						dayS = dayS - (LeapYear[m_Month] - m_Day ) - 1;
						m_Day = 1;
						m_Month = 1;
						m_Year++;
					} 
					else
					{
						dayS = dayS - (LeapYear[m_Month] - m_Day ) - 1;
						m_Month++;
						m_Day = 1;
					}
				
				}
				else if ( dayS <= LeapYear[m_Month] - m_Day)
				{
					m_Day = m_Day + dayS;
			        dayS = 0;  	
				}
			}
			else
			{
				 if ( dayS > OrdinaryYear[m_Month]-m_Day )
				{
					if ( m_Month == 12) 
					{
						dayS = dayS - (OrdinaryYear[m_Month] - m_Day ) - 1;
						m_Day = 1;
						m_Month = 1;
						m_Year++;
					} 
					else
					{
						dayS = dayS - (OrdinaryYear[m_Month] - m_Day ) - 1;
						m_Month++;
						m_Day = 1;
					}
				
				}
				else  if ( dayS < OrdinaryYear[m_Month] - m_Day)
				{
					m_Day = m_Day + dayS;
			        dayS = 0;  	
				}
			}
		}	
	return *this;	
		
	}
	
	Calendar& operator- (int dayS)
	{
        while ( dayS/366>0 )
        {    
//		    std::cout << "Start section 365";         
			if ( ( ( m_Year%4==0 )&&( m_Year%100!=0 )||( m_Year%400==0 ) ) && ( ( m_Month > 2 ) || (m_Day ==29) && ( m_Month ==2 ) ) )
			{
				dayS = dayS - 366;
				m_Year--;
//				std::cout << " -366" << std::endl;
			}
			else if ( ( ( m_Year%4==0 )&&( m_Year%100!=0 )||( m_Year%400==0 ) ) && ( m_Month <=2 ) )
			{
				dayS = dayS - 365;
				m_Year--;
//				std::cout << " -365" << std::endl;
			}
			else if ( ( ( (m_Year-1) % 4 == 0 )&&(  ( m_Year-1) % 100 != 0 )||( ( m_Year-1) % 400 == 0 ) ) && ( m_Month <=2 )  )
			{
				dayS = dayS - 366;
				m_Year--;
//				std::cout << " -366" << std::endl;
			}
			else 
			{
				dayS = dayS - 365;
				m_Year--;
//				std::cout << " -365" << std::endl;
			}			
		}
		
//			std::cout << "dayS 365 = " << dayS << std::endl;
//			std::cout << "Current data is : " << "Day - " << m_Day << ", Month - " << m_Month << ", Year - " << m_Year << std::endl;
// Работает корректно		
		
		if ( dayS > m_Day )
		{
			dayS = dayS - m_Day;
			if ( ( m_Year%4==0 )&&( m_Year%100!=0 )||( m_Year%400==0 ) )
			{
				if ( m_Month == 1)
				{
					m_Year--;
					m_Month = 12;
					m_Day = 31;
				}
				else 
				{
					m_Month--;
					m_Day = LeapYear[m_Month];
				}
				std::cout << "dayS = " << dayS << std::endl;
				std::cout << "Current data is : " << "Day - " << m_Day << ", Month - " << m_Month << ", Year - " << m_Year << std::endl;	
			}
			else
			{
				if ( m_Month == 1)
				{
					m_Year--;
					m_Month = 12;
					m_Day = 31;
				}
				else 
				{
					m_Month--;
					m_Day = OrdinaryYear[m_Month];
				}
				std::cout << "dayS = " << dayS << std::endl;
				std::cout << "Current data is : " << "Day - " << m_Day << ", Month - " << m_Month << ", Year - " << m_Year << std::endl;
			} 
	    }
//  Корректный код

		
		while (dayS > m_Day)
		{
			if ( ( m_Year%4==0 )&&( m_Year%100!=0 )||( m_Year%400==0 ) )
			{
				dayS = dayS - m_Day;
				if ( m_Month == 1)
				{
					m_Year--;
					m_Month = 12;
					m_Day = 31;
				}
				else 
				{
					m_Month--;
					m_Day = LeapYear[m_Month];
				}
			}
			else 
			{
				dayS = dayS - m_Day;
				if ( m_Month == 1)
				{
					m_Year--;
					m_Month = 12;
					m_Day = 31;
				}
				else 
				{
					m_Month--;
					m_Day = OrdinaryYear[m_Month];
				}
			} 
		}
			
		if ( dayS <= m_Day) 
		{
		   m_Day = m_Day - dayS;
		   dayS = 0;	
		}
		else 
		{
		
			m_Day = m_Day - dayS;
			dayS = 0;
		}
	}
	
	friend int operator-(Calendar const &first, Calendar const &second);
	
};
	
	
int operator-(Calendar const &first, Calendar const &second) 
{
	if ( (first.m_Year == second.m_Year)&&(first.m_Month == second.m_Month) ) 
	{
	   return abs(first.m_Day - second.m_Day);	
	}
	
			
	if ( (first.m_Year == second.m_Year)&&(first.m_Month > second.m_Month) )
	{
		if ( ( first.m_Year%4==0 )&&( first.m_Year%100!=0 )||( first.m_Year%400==0 ) )
		{
			int TempDays = first.LeapYearMonthSumm[first.m_Month] -  first.LeapYearMonthSumm[second.m_Month] + ( first.LeapYear[second.m_Month] - second.m_Day ) - ( first.LeapYear[first.m_Month] - first.m_Day );
            return TempDays;
		}
		else 
		{
			int TempDays = first.OrdinaryYearMonthSumm[first.m_Month] -  first.OrdinaryYearMonthSumm[second.m_Month] + ( first.OrdinaryYear[second.m_Month] - second.m_Day ) - ( first.OrdinaryYear[first.m_Month] - first.m_Day );
            return TempDays;			
		}
	}
	
	if ( (first.m_Year == second.m_Year)&&(first.m_Month < second.m_Month) )
	{
		if ( ( first.m_Year%4==0 )&&( first.m_Year%100!=0 )||( first.m_Year%400==0 ) )
		{
			int TempDays = first.LeapYearMonthSumm[second.m_Month] -  first.LeapYearMonthSumm[first.m_Month] + ( first.LeapYear[first.m_Month] - first.m_Day ) - ( first.LeapYear[second.m_Month] - second.m_Day );
            return TempDays;
		}
		else 
		{
			int TempDays = first.OrdinaryYearMonthSumm[second.m_Month] -  first.OrdinaryYearMonthSumm[first.m_Month] + ( first.OrdinaryYear[first.m_Month] - first.m_Day ) - ( first.OrdinaryYear[second.m_Month] - second.m_Day );
            return TempDays;			
		}
	}
	
	if (first.m_Year != second.m_Year)
	{
		int TempDays = 0;
		int HigerDay;
		int HigerMonth;
		int HigerYear;
		int LowerDay;
		int LowerMonth;
		int LowerYear;
		if (first.m_Year > second.m_Year)
		{
			HigerDay = first.m_Day;
			HigerMonth = first.m_Month;
			HigerYear = first.m_Year;
			LowerDay = second.m_Day;
			LowerMonth = second.m_Month;
			LowerYear = second.m_Year;
		}
		else
		{
			HigerDay = second.m_Day;
			HigerMonth = second.m_Month;
			HigerYear = second.m_Year;
			LowerDay = first.m_Day;
			LowerMonth = first.m_Month;
			LowerYear = first.m_Year;
		}
		
		if ( ( LowerYear%4==0 )&&( LowerYear%100!=0 )||( LowerYear%400==0 ) )
		{
			TempDays = TempDays + (first.LeapYear[LowerMonth] - LowerDay ) + ( first.LeapYearMonthSumm[12] - first.LeapYearMonthSumm[LowerMonth] );
		}
		else 
		{
			TempDays = TempDays + (first.OrdinaryYear[LowerMonth] - LowerDay ) + ( first.OrdinaryYearMonthSumm[12] - first.OrdinaryYearMonthSumm[LowerMonth] );		
		}
		
		while (LowerYear != HigerYear)
		{
		    if ( (HigerYear - LowerYear) == 1 ) break;
		    else 
		    {
		    	LowerYear++;
		    	if ( ( LowerYear%4==0 )&&( LowerYear%100!=0 )||( LowerYear%400==0 ) )  TempDays = TempDays + 366;
				else TempDays = TempDays + 365;
		    }	
		}
		
		if ( ( HigerYear%4==0 )&&( HigerYear%100!=0 )||( HigerYear%400==0 ) )
		{
			TempDays = TempDays + first.LeapYearMonthSumm[HigerMonth] - ( first.LeapYear[HigerMonth]- HigerDay);
		}
		else 
		{
			TempDays = TempDays + first.OrdinaryYearMonthSumm[HigerMonth] - ( first.OrdinaryYear[HigerMonth]- HigerDay);
		}


        return TempDays;
    }
}	
		
	
	
int main()
{
	Calendar C1{10, 3, 2020};
	Calendar C2{11, 5, 2017};
	Calendar C3{29, 5, 2017};
	Calendar C4{10, 3, 2020};
	std::cout << "Date in class:" << std::endl;
	std::cout << "Day - " << C1.GetDay() << ", Month - " << C1.GetMonth() << ", Year - " << C1.GetYear() << std::endl;
	
	C1+6144;
	
	std::cout << "Date in class:" << std::endl;
	std::cout << "Day - " << C1.GetDay() << ", Month - " << C1.GetMonth() << ", Year - " << C1.GetYear() << std::endl;
	
	std::cout << "==================================================================" << std::endl;
	std::cout << "Date in class:" << std::endl;
	std::cout << "First Date.  Day - " << C2.GetDay() << ", Month - " << C2.GetMonth() << ", Year - " << C2.GetYear() << std::endl;
	std::cout << "Second Date.  Day - " << C3.GetDay() << ", Month - " << C3.GetMonth() << ", Year - " << C3.GetYear() << std::endl;
    std::cout << "Difference between C2 and C3 - " << C2 - C3 << " days" << std::endl;	
	
	C4-1660;
	std::cout << "C4 Date ( after ' - ' )in class:" << std::endl;
	std::cout << "Day - " << C4.GetDay() << ", Month - " << C4.GetMonth() << ", Year - " << C4.GetYear() << std::endl;
	
	return 0;
	
	
}
	

