#include <iostream>
#include <cassert>

class Calendar
{
	private:
	int m_Day;
	int m_Month;
	int m_Year;
	int LeapYear[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int OrdinaryYear[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   	int LeapYearMonthSumm[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	int OrdinaryYearMonthSumm[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

	
			
	public:
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
/*		
		if ( ( ( m_Year%4==0 )&&( m_Year%100!=0 )||( m_Year%400==0 ) ) && ( LeapYear[m_Month] >= (m_Day + dayS) ) )
		{
			m_Day = m_Day + dayS;
			dayS = 0;
		}
		else 
		{
		    if ( OrdinaryYear[m_Month] >= (m_Day + dayS) ) 
			{
			    m_Day = m_Day + dayS;
			    dayS = 0;		
			}	
		}
		
*/		
		while (dayS !=0)
		{
			std::cout << "Cycle on" << std::endl; // Trassing
			assert ( ( dayS >= 0 ) && "Error - dayS < 0 and cycle not ended" );
			if ( ( m_Year%4==0 )&&( m_Year%100!=0 )||( m_Year%400==0 ) )
			{
				std::cout << "Start Leap Year" << std::endl; // Trassing
			    if ( dayS > LeapYear[m_Month]-m_Day )
				{
					assert ( m_Month<13 && "Month index higer than 12" );
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
				    assert ( dayS > 0 && "dayS < 0  - ALARM !!" );
					m_Day = m_Day + dayS;
			        dayS = 0;  	
				}
				std::cout << "End Leap Year" << std::endl; // Trassing
			}
			else
			{
				std::cout << "Start Ordinary Year" << std::endl; // Trassing
				 if ( dayS > OrdinaryYear[m_Month]-m_Day )
				{
					assert ( m_Month<13 && "Month index higer than 12" );
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
				    assert ( dayS > 0 && "dayS < 0  - ALARM !!" );
					m_Day = m_Day + dayS;
			        dayS = 0;  	
				}
				std::cout << "End Ordinary Year" << std::endl; // Trassing
			}
			std::cout << "Cycle end" << std::endl; // Trassing	
		}	
	return *this;	
		
	}
	
	
};
	
int main()
{
	Calendar C1{10, 3, 2020};
	std::cout << "Date in class:" << std::endl;
	std::cout << "Day - " << C1.GetDay() << ", Month - " << C1.GetMonth() << ", Year - " << C1.GetYear() << std::endl;
	
	C1+2880;
	
	std::cout << "Date in class:" << std::endl;
	std::cout << "Day - " << C1.GetDay() << ", Month - " << C1.GetMonth() << ", Year - " << C1.GetYear() << std::endl;
	return 0;
}
	

