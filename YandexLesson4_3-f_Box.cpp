#include <iostream>
#include <list>
#include <time.h>
#include <algorithm>
		

class Stock
{
	
		
	private:
		struct box
		{
			int Wi;
			int Vi;
			int Serial;
			long long AddDate;
		};
		int SerialNumber = 0;
		std::list<box>BoxArray;
	
	public:	
		friend bool SortFunction(const box &b1, const box &b2);
	    void Add(int w, int v)
	    {
	    	box boxX;
			boxX.Wi = w;
			boxX.Vi = v;
			boxX.Serial = SerialNumber+1;
			boxX.AddDate = time(NULL);
			BoxArray.push_back(boxX);
			SerialNumber++;
//			if (BoxArray.size() >=2 )  BoxArray.sort(SortFunction); 
			if (BoxArray.size() >=2 )  BoxArray.sort([](const box &b1, const box &b2) {	if  (b1.Wi < b2.Wi) return true;
    																					if ( (b1.Wi == b2.Wi) && ( (b1.AddDate>b2.AddDate) || (b1.AddDate==b2.AddDate) ))  return true;  
																						else return false;} );         
		}
		
// ==================Trassing Code=================================================		
		int GetSerialNumber()
		{
			return SerialNumber; 	
     	}
		 
		void PrintList()
		{
			for (auto ValueX : BoxArray)
			{
				std::cout << "Box Serial - " << ValueX.Serial << ". Weight - " << ValueX.Wi << ". Volume - " << ValueX.Vi << ". Add time - " << ValueX.AddDate << std::endl;
			} 
				
		}
		  
// ===================Trassing Code=================================================

	
    	int GetByW(int min_w) 
		{
			if ( BoxArray.size()==0 ) return -1;
			int TempValue(0);
			auto IterMinimunWeight = std::find_if( BoxArray.begin(), BoxArray.end(), [min_w](const box &a)->bool {  if (a.Wi == min_w) return true; 
																													else return false; } );
			if 	( IterMinimunWeight == BoxArray.end() )	
			{
				IterMinimunWeight = std::find_if( BoxArray.begin(), BoxArray.end(), [min_w](const box &a)->bool {  if (a.Wi > min_w) return true; 
																													else return false; } );
			}
		
			TempValue = (*IterMinimunWeight).Serial;
			std::cout << "Value min_w - " << min_w << ".  Serial is - " << TempValue << std::endl;
			BoxArray.erase(IterMinimunWeight);
			return TempValue; 
		}
	
		int GetByV(int min_v)
		{
			if ( BoxArray.size()==0 ) return -1;
			box &TempBox = BoxArray.front();
			int Temp_Vi = TempBox.Vi; 
			int Temp_AddDate = TempBox.AddDate;
			int Temp_Serial = TempBox.Serial;
			for (auto IterMinimunWeight = BoxArray.begin(); IterMinimunWeight != BoxArray.end(); IterMinimunWeight++)
			{
				if ( (*IterMinimunWeight).Vi < min_v )   continue;
				if (  ((*IterMinimunWeight).Vi != min_v ) && ( Temp_Vi == min_v ) ) continue;
				if (  ((*IterMinimunWeight).Vi == min_v ) && ( Temp_Vi != min_v ) )
				{
					Temp_Vi = (*IterMinimunWeight).Vi; 
					Temp_AddDate = (*IterMinimunWeight).AddDate;
					Temp_Serial = (*IterMinimunWeight).Serial;
					continue;
				}
				
				if (  ((*IterMinimunWeight).Vi == min_v ) && ( Temp_Vi == min_v ) )
				{
					if ( (*IterMinimunWeight).AddDate < Temp_AddDate )
					{
						Temp_AddDate = (*IterMinimunWeight).AddDate;
						Temp_Serial = (*IterMinimunWeight).Serial;
						continue;
					}
					else continue;
				}
				
				if (  ((*IterMinimunWeight).Vi > min_v ) && ( Temp_Vi != min_v ) )
				{
					if ( (*IterMinimunWeight).Vi < Temp_Vi )
					{
						Temp_Vi = (*IterMinimunWeight).Vi;
						Temp_AddDate = (*IterMinimunWeight).AddDate;
						Temp_Serial = (*IterMinimunWeight).Serial;
						continue;
					}
					else continue;
				}
				
			}

/*			auto IterMinimunWeight = std::find_if( BoxArray.begin(), BoxArray.end(), [min_v, Temp_Vi, Temp_AddDate](const box &a)->bool {  if (a.Vi == min_v) return true; 
																																			 else return false; } );
			std::cout << "Serial is - " << (*IterMinimunWeight).Serial << std::endl;
			TempValue = (*IterMinimunWeight).Serial;
			BoxArray.erase(IterMinimunWeight);
*/
			std::cout << "Serial is - " << Temp_Serial << std::endl;
			return Temp_Serial; 
		}
	
	
};

/*
bool SortFunction(const Stock::box &b1, const Stock::box &b2)
{
	if  (b1.Wi > b2.Wi) return true;
    if ( (b1.Wi == b2.Wi) && ( (b1.AddDate<b2.AddDate) || (b1.AddDate==b2.AddDate) ))  return true;  
	else return false;
}
*/		


int main ()
{
	Stock Stx;
	Stx.Add (12, 4);
		system("pause");
	Stx.Add (16, 3);
		system("pause");
	Stx.Add (24, 8);
		system("pause");
	Stx.Add (4, 1);
		system("pause");
	Stx.Add (4, 2);
		system("pause");
	Stx.Add (2, 1);
		system("pause");
	Stx.Add (3, 2);
		system("pause");
	Stx.Add (3, 1);
		system("pause");
	Stx.Add (4, 8);
		system("pause");
	Stx.Add (5, 3);
		system("pause");
	Stx.Add (32, 12);
		system("pause");
	Stx.Add (6, 4);
		system("pause");
	Stx.Add (8, 2);
		system("pause");
	Stx.Add (8, 5);
		system("pause");
	Stx.Add (12, 8);
		system("pause");
	Stx.Add (7, 4);
		system("pause");
	Stx.Add (6, 2);
		system("pause");
	Stx.Add (3, 2);
		system("pause");
	Stx.Add (4, 1);
		system("pause");
	Stx.Add (6, 2);
		system("pause");
	Stx.Add (5, 2);
		system("pause");
	Stx.Add (5, 3);
		system("pause");
	Stx.Add (6, 4);
		system("pause");
	Stx.Add (2, 2);
	Stx.PrintList();
	
	Stx.GetByV(2);
		std::cout << std::endl;
	Stx.GetByV(11);
		std::cout << std::endl;
	Stx.GetByV(5);
		std::cout << std::endl;
	Stx.GetByV(9);
		std::cout << std::endl;
	Stx.GetByV(6);
	
	std::cout << std::endl;
	Stx.GetByW(6);
	std::cout << std::endl;
	Stx.GetByW(14);
	std::cout << std::endl;
	Stx.GetByW(7);
	std::cout << std::endl;
	Stx.GetByW(8);
	std::cout << std::endl;
	Stx.GetByW(12);
	std::cout << std::endl;
	Stx.GetByW(6);
	std::cout << std::endl;
	Stx.GetByW(5);
	std::cout << std::endl;
	Stx.GetByW(11);
	std::cout << std::endl;
	Stx.PrintList();	
	
}