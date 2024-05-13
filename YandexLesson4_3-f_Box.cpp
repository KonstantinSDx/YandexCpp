#include <iostream>
#include <list>
#include <time.h>


struct box
{
	int Wi;
	int Vi;
	int Serial;
	long long AddDate;
};
		
bool SortFunction(const box &b1, const box &b2)
{
	if  (b1.Wi > b2.Wi) return true;
    if ( (b1.Wi == b2.Wi) && ( (b1.AddDate<b2.AddDate) || (b1.AddDate==b2.AddDate) ))  return true;  
	else return false;
}

class Stock
{
	private:
		int SerialNumber = 0;
		std::list<box> BoxArray;
	
	public:	
	    void Add(int w, int v)
	    {
	    	box boxX;
			boxX.Wi = w;
			boxX.Vi = v;
			boxX.Serial = SerialNumber+1;
			boxX.AddDate = time(NULL);
			BoxArray.push_back(boxX);
			SerialNumber++;
			if (BoxArray.size() >=2 )  BoxArray.sort(SortFunction);          
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
			return 0;
		}
	
		int GetByV(int min_v)
		{
			return 0;
		}
	
	
};




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
	
	
}