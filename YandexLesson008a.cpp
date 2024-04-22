#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out)
{
	
		for ( auto Iter_first1 = first1; Iter_first1 != last1; Iter_first1++)
	{
		auto IterY = std::find ( first2, last2, *Iter_first1);
		if (IterY == last2)
		{
			*out = *Iter_first1;
			 out++;
		}	
	}
	
	return out;
};
                      



template <typename Iter>
Iter Unique(Iter first, Iter last)
{
	auto IterStart = first;          // trassing code
	auto IterEnd = last;             // trassing code  
	
	auto LastElement = *first;
	first++;
	bool CycleOn=true;
	while ( first != last )
	{
		if ( LastElement == (*first) )
		{
			for (auto IterReplace = first; IterReplace != last; IterReplace++)
			{
			    if ( *first != *IterReplace ) 
				{
					std::swap (*first, *IterReplace);
					CycleOn=true;
					break;
				}
				else {  CycleOn=false;  }	
			}					
		}
		else 
		{
			LastElement = *first;
			first++;
		}
		if ( !CycleOn ) 
		{
			for ( ; IterStart != IterEnd; IterStart++) std::cout << *IterStart << " ";  // trassing code
			std::cout << std::endl;                                                     // trassing code
		    return first;	
		}
		
	}
	
	for ( ; IterStart != IterEnd; IterStart++) std::cout << *IterStart << " ";      // trassing code
	std::cout << std::endl;                                                          // trassing code
	return first;
};

class Fruit
{
	private:
    std::string name;
    std::string color;		
    
    public:
    Fruit (std::string f_name, std::string f_color) : name(f_name), color(f_color)
	{
		
	}  	
	
	std::string GetName() const
	{
		return name;
	}

    std::string GetColor() const
	{
		return color;
	}
		
};

class Apple : public Fruit
{
	private:
	double fiber;
	
	public:
	Apple( std::string a_name, std::string a_color, double a_fiber) : Fruit(a_name, a_color), fiber(a_fiber) 
	{
		
	} 	
	friend std::ostream& operator<< (std::ostream &OutLine, const Apple &ap1);
	
};

class Banana : public Fruit
{
	public:
	Banana (std::string b_name, std::string b_color) : Fruit (b_name, b_color)
	{
		
	}	
	
	friend std::ostream& operator<< (std::ostream &OutLine, const Banana &bn1); 
};

std::ostream& operator<< (std::ostream &OutLine, const Apple &ap1)
{
	OutLine << "Apple(" << ap1.GetName() << ", " << ap1.GetColor() << ", " << ap1.fiber << ")"  << std::endl;
	return OutLine;   
}

std::ostream& operator<< (std::ostream &OutLine, const Banana &bn1)
{
	OutLine << "Banana(" << bn1.GetName() << ", " << bn1.GetColor() << ")" << std::endl;
	return OutLine;   
}
	

int main()
{
     
     std::vector<int>MyString2 { 2, 2, 12, 33, 5, 51, 6, 72, 7, 48, 13, 4, 25, 64, 17, 7, 11, 19, 21, 1, 1, 1, 1, 91, 6 };
     std::vector<int>MyString3 { 2, 6, 17, 43, 55, 65, 26, 78, 79, 81, 3, 4, 15, 96, 47, 70, 1, 15, 14, 1, 19, 1, 1, 1, 26 };
     std::vector<int>MyString4;
     MyString4.resize(32);
     auto InterEnd = SetDifference (MyString2.begin(), MyString2.end(), MyString3.begin(), MyString3.end(), MyString4.begin());
     for ( auto IterF = MyString4.begin(); IterF != InterEnd; IterF++)
    {
    	std::cout << *IterF << " ";
    }
     
     
/*    
    std::vector<int>MyString { 2, 2, 2, 3, 5, 5, 6, 7, 7, 8, 3, 4, 5, 6, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 6 };
	auto IterX = Unique( MyString.begin(), MyString.end() ); 
    for ( auto IterC = MyString.begin(); IterC != IterX; IterC++)
    {
    	std::cout << *IterC << " ";
    }
*/
	
/*	
	const Apple a("Red delicious", "red", 7.3);
	std::cout << a;
 
	const Banana b("Cavendish", "yellow");
	std::cout << b;
*/	
	return 0;
}
 
