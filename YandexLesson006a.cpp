#include <iostream>
#include <vector>
#include <string>
#include <list>

/*
template <typename T>
void Print (const T &Val1, const std::string &DelimiterX)
{
	auto Iterator1 = Val1.begin();
	for ( const auto &ElementX : Val1)
	{
		std::cout << ElementX;
		Iterator1++;
		if ( Iterator1 == Val1.end() ) std::cout << "\n";
		else std::cout << DelimiterX;
	}
}
*/

/*
void MakeTrain(void)
{
	int TempNumber;
	int NumberCarriageToAction;
	std::deque<int>Train;
	std::string CommandX;
	for (int i=0; i<4; i++)
	{
		std::cin >> CommandX >> TempNumber;
		if (CommandX == "+left") Train.push_front(TempNumber);
		if (CommandX == "+right") Train.push_back(TempNumber);

		if (CommandX == "-left") 
		{
			auto TrainIterator = Train.begin();
		    if ( TempNumber >= Train.size() ) Train.clear(); 
			else Train.erase(TrainIterator, TrainIterator+TempNumber);	
		}
		
		if (CommandX == "-right")
		{
			auto TrainIterator = Train.end();
		    if ( TempNumber >= Train.size() ) Train.clear(); 
			else Train.erase(TrainIterator-TempNumber, TrainIterator);	
		}
		CommandX.clear();
		  
	}
	
	for (unsigned int i=0; i<Train.size(); i++)
	{
		if ( i < Train.size()-1 )  std::cout << Train[i] << " ";
		else  std::cout << Train[i] << "\n";
	}
	
}     
*/


int main()
{
     std::list<std::string>StringList;
     std::string TempStr;
	 TempStr.reserve(3000);
	 bool CycleON = true;
	 while(true)
     {
     	std::getline(std::cin, TempStr);
		StringList.push_back(TempStr); 
     	if ( TempStr.empty() ) break;
     }
    
     auto IterX = StringList.begin();
	 bool ShiftOn = false;
	 auto ShiftIterStart = StringList.begin();
	 auto ShiftIterEnd = StringList.begin();
	 std::list<std::string>TempShiftBuffer; 
     std::string Buffer = "";
     while(CycleON)
     {
        TempStr.clear();
     	std::getline (std::cin, TempStr);
		if ( TempStr.empty() ) CycleON = false;
		
		if ( (TempStr == "Shift") && (ShiftOn == false) ) 
		{
			ShiftOn = true;
			ShiftIterStart = IterX;
			ShiftIterEnd = IterX;
		}
				
//		if ( (TempStr == "Up") && (IterX != StringList.begin()) && !ShiftOn )  IterX--;
        if ( (TempStr == "Up") && (IterX != StringList.begin()) )  IterX--;	
		if ( (TempStr == "Down") && (IterX != (--StringList.end()) ) && !ShiftOn ) IterX++;
		
		if ( (TempStr == "Down") && (IterX != (--StringList.end()) ) && ShiftOn ) 
		{
		    IterX++;
			ShiftIterEnd = IterX;
		}
				
		if ( (TempStr == "Ctrl+X") && ( *IterX != "") && !ShiftOn )
		{
			TempShiftBuffer.clear();
			Buffer = *IterX;
			StringList.erase(IterX++);
		}
		
		if ( (TempStr == "Ctrl+X") && ( *IterX != "")  && ShiftOn )
		{
			Buffer.clear();
			TempShiftBuffer.assign(ShiftIterStart, ShiftIterEnd);
			ShiftOn = false;
			IterX = StringList.erase(ShiftIterStart, ShiftIterEnd);
		}
		
		if ( (TempStr == "Ctrl+V") && !Buffer.empty() && !ShiftOn )  StringList.insert(IterX, Buffer);

        if ( (TempStr == "Ctrl+V") && !Buffer.empty() && ShiftOn )
		{
		   StringList.erase(ShiftIterStart, IterX++);
		   StringList.insert(IterX, Buffer);
		   ShiftOn = false;
		}
         
		if ( (TempStr == "Ctrl+V") && !TempShiftBuffer.empty() && ShiftOn )   
		{
		   StringList.erase(ShiftIterStart, IterX++);
		   StringList.splice(IterX, TempShiftBuffer);
		   ShiftOn = false;	
		} 

        if ( (TempStr == "Ctrl+V") && !TempShiftBuffer.empty() && !ShiftOn )  StringList.splice(IterX, TempShiftBuffer);
		
		
//================================================================================================
	    for ( auto Iter_For_Cycle = StringList.begin(); Iter_For_Cycle != StringList.end(); Iter_For_Cycle++)
      {
      	    std::cout << *Iter_For_Cycle; 
			if (Iter_For_Cycle == IterX)  std::cout << "       <-" << std::endl;
			else std::cout << std::endl;
      }
      
        std::cout << "Current Buffer content : ";
        if ( Buffer.empty() ) std::cout << " Buffer is empty." << std::endl;
        else std::cout << Buffer  << std::endl;
		
		std::cout << "Current TempShiftBuffer content : ";
		if ( TempShiftBuffer.empty() )  std::cout << " TempShiftBuffer is empty." << std::endl;
		else
		{
			std::cout << std::endl;
			for ( std::string &StringTemp : TempShiftBuffer )
            {
      	       std::cout << StringTemp << std::endl;
            }
      
		}
		std::cout << std::endl;
		
//================================================================================================		
			
     }     

      for ( std::string &StringX : StringList )
      {
      	    if (StringX != "") std::cout << StringX << std::endl;
			else std::cout << StringX;
      }
      
/*	
     MakeTrain();	
*/

/*    
	unsigned int NumberOfStudent;
	std::cin >> NumberOfStudent;
	std::string StudentName;
	std::string TopOrBottom;
	std::deque<int> IndexOfWorkVector;
	std::deque<std::string>StudentWork;
	for (unsigned int i=0; i<NumberOfStudent; i++)
	{
		std::cin >> StudentName >> TopOrBottom;
		if (TopOrBottom == "top") StudentWork.push_front(StudentName);
		if (TopOrBottom == "bottom") StudentWork.push_back(StudentName);
		StudentName.clear();
		TopOrBottom.clear();
	}	

	unsigned int NumbersOfWorkToTest;
	std::cin >> NumbersOfWorkToTest;
	unsigned int IndexOfWork;
	for (unsigned int i=0; i<NumbersOfWorkToTest; i++)
	{
		std::cin >> IndexOfWork;
		IndexOfWorkVector.push_back(IndexOfWork);
	}
	
	for (unsigned int i=0; i<NumbersOfWorkToTest; i++)
	{
		std::cout << StudentWork[ IndexOfWorkVector[i]-1 ] << std::endl;
	}
*/	
	
		
/*
	std::vector<int> data = {1, 2, 3, 4};
    Print(data, ", ");
*/	
	return 0;
}
