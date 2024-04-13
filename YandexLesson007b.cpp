#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

/*
class MyStringX
{
    std::string StringX;
	
	public:
	MyStringX()
	{
		StringX = "";
	}	
	
	MyStringX( std::string Str1) : StringX(Str1)
	{

	}
	
	std::string operator()(int StartIndex, int Length)
	{
		std::string TempStr(StringX, StartIndex, Length);
		return TempStr; 
	}
};
*/


/*
struct StudentGrade
{
   std::string StudentName;
   char Grade;	
};

class GradeMap
{
    std::vector<StudentGrade>m_map;
	
public:
    GradeMap()
	{
		
	}	
	
	char& operator[](std::string StringX)
	{
		for (StudentGrade StGr : m_map)
		{
			if ( StGr.StudentName == StringX ) return  StGr.Grade;
		}
	    StudentGrade TempStudent {StringX, 'N'};
		m_map.push_back(TempStudent);
		return m_map[m_map.size()-1].Grade;		
	}	
};
*/

int main ()
{

    unsigned int NumberOfWord;
    int AnargammLength;
    std::cin >> NumberOfWord >> AnargammLength;
    std::map<std::string, unsigned int> AnargammMap;
    std::string word;
    for (unsigned int i=0; i<NumberOfWord; i++)
    {
       std::cin >> word;
	   for (unsigned int j=0; j<word.size()-1; j++ )
	   {
	   	  std::string TempStr(word, j, 2);
		  AnargammMap[TempStr]++;   
	   }	
    }
    
    
    std::multimap<unsigned int, std::string>SortedAnagramm;
    for (const auto &ElementX : AnargammMap)
    {
    	SortedAnagramm.insert({ElementX.second, ElementX.first});
    }


    auto Iter2 = ( --SortedAnagramm.end() );
	int MaxKey = Iter2->first;
    std::string SortedAnagrammOut;
	for (unsigned int i = MaxKey; i>0; i--)
	{
		auto IterTrmp = SortedAnagramm.lower_bound(i);
		for ( ; IterTrmp != SortedAnagramm.end(); IterTrmp++)
		{
			SortedAnagrammOut.clear();
			SortedAnagrammOut = SortedAnagrammOut + IterTrmp->second + " - " + std::to_string(IterTrmp->first); 
			std::cout << SortedAnagrammOut << std::endl;
		}
		IterTrmp = SortedAnagramm.lower_bound(i);
		SortedAnagramm.erase(IterTrmp, SortedAnagramm.end());		
	}
	   


/*    
    unsigned int NumberOfWord;
    std::cin >> NumberOfWord;
    std::cout << std::endl;
    std::string KeyWord;
    unsigned int NumberOfPage;
    std::multimap<int, std::string> ItemPointerTemp;
    std::map<int, std::string> ItemPointerMain;
    
    for (unsigned int i=0; i<NumberOfWord; i++ )
    {
    	std::cin >> KeyWord >> NumberOfPage;
		ItemPointerTemp.insert({NumberOfPage, KeyWord});
    }

    
    std::string CurrentPageWord;
    auto IterForCurrentPage = ItemPointerTemp.begin();
    int CurrentPage = IterForCurrentPage->first;
    std::set<std::string>CurrentStrSet;
    
    for (auto IterF = ItemPointerTemp.begin() ; IterF != ItemPointerTemp.end(); IterF++)
	{
		if ( (CurrentPage == IterF->first) )  CurrentStrSet.insert(IterF->second); 
		else
		{
			for (auto IterSet = CurrentStrSet.begin(); IterSet != CurrentStrSet.end(); IterSet++)
			{
				if ( IterSet != CurrentStrSet.begin() ) CurrentPageWord = CurrentPageWord + " "; 
			    CurrentPageWord = CurrentPageWord + *IterSet;
			}
			ItemPointerMain.insert ({CurrentPage, CurrentPageWord});
			CurrentStrSet.clear();
			CurrentPageWord.clear();
			CurrentPage = IterF->first;
			CurrentStrSet.insert(IterF->second); 
		}				 
		
	}
	
	if ( !CurrentStrSet.empty() ) 
	{
	   	for (auto IterSet = CurrentStrSet.begin(); IterSet != CurrentStrSet.end(); IterSet++)
		{
			if ( IterSet != CurrentStrSet.begin() ) CurrentPageWord = CurrentPageWord + " "; 
		    CurrentPageWord = CurrentPageWord + *IterSet;
		}	
		ItemPointerMain.insert ({CurrentPage, CurrentPageWord});
	}
	
    for ( auto &page : ItemPointerMain)
	{
		std::cout << page.first << " " << page.second << std::endl; 
	}
*/

    
        
/*    
	for (auto IterF = ItemPointerTemp.begin() ; IterF != ItemPointerTemp.end(); IterF++)
	{
		if ( (CurrentPage == IterF->first) && ( CurrentWord != IterF->second ) ) 
		{
			if ( IterF != ItemPointerTemp.begin() ) CurrentPageWord = CurrentPageWord + " "; 
			CurrentWord = IterF->second;
			CurrentPageWord = CurrentPageWord + CurrentWord; 
		} 
	    else if ( (CurrentPage == IterF->first) && ( CurrentWord == IterF->second ) )
	    {
	    	CurrentWord = IterF->second;	 
	    }
	    else
		{
			ItemPointerMain.insert ({CurrentPage, CurrentPageWord});
			CurrentPage = IterF->first;
			CurrentPageWord = IterF->second;
			CurrentWord = IterF->second; 
		}				 
	}
	
	if ( !CurrentPageWord.empty() ) 
	{
	   ItemPointerMain.insert ({CurrentPage, CurrentPageWord});	
	}
    
    for ( auto &page : ItemPointerMain)
	{
		std::cout << page.first << " " << page.second << std::endl; 
	}
*/	
	    
	
/*
    MyStringX string("Hello, world!");
    std::cout << string(7, 6);
*/


/*
   	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';
*/
	
/*	
   std::string FilePathTemp;
   unsigned int NumberOfPath = 6;
   std::set<std::string>FileSet;
   for ( unsigned int i = 0; i < NumberOfPath; i++)
   {
   	  std::string StringToSet;
   	  std::getline(std::cin, FilePathTemp);
	  for (unsigned int j=0; j<FilePathTemp.size(); j++)
	  {
	     if ( FilePathTemp[j]=='/' && FilePathTemp[j+1]!='/' && (j+1) != FilePathTemp.size() ) 
		 {
		 	StringToSet = StringToSet + FilePathTemp[j];
		 	FileSet.insert(StringToSet);
		 }
		 else StringToSet = StringToSet + FilePathTemp[j]; 	
	  }   
   }

   for ( std::string StrX : FileSet)
   {
   	  std::cout << StrX << std::endl;
   }
*/

   
return 0;	
}
