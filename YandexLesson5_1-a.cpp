#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T>
class Table
{
	private:
		int m_X;
		int m_Y;
		std::vector<std::vector<T>>TableArray;
		
	public:
		Table (size_t X, size_t Y) : m_X(X), m_Y(Y) 
		{
			TableArray.resize(Y);
			for (size_t i = 0; i < Y; i++)
			{
				TableArray[i].resize(X);
			}
		}
		
		std::vector<T>& operator[](const int ValY)
	    {
	    	return TableArray[ValY];
		}
		
		const std::vector<T>& operator[](const int ValY) const
	    {
	    	return TableArray[ValY];
		}
		
		void resize(size_t X_res, size_t Y_res)
		{
			TableArray.resize(Y_res);
			for (size_t i = 0; i < Y_res; i++)
			{
				TableArray[i].resize(X_res);
			}
		}
		
		const std::pair<size_t, size_t> size() const
		{
			std::pair<size_t, size_t> ReturnValue;
			ReturnValue.first = m_X;
			ReturnValue.second = m_Y;
			return ReturnValue;
		}
};

int main()
{
	
	Table<int> Tb1(4,4);
	Tb1[0][0] = 1;
	const Table<int> Tb2(6,6);
	if ( Tb2[0][0] == 1 ) std::cout << "Value 1 On";
	Table<double> Tb3(9,5);
	
//=========================Test Block 1 - Delete later=============================================================	
	std::vector<std::vector<int>>TableArray(8, std::vector<int>(8));
	
	for (size_t i = 0; i<8; i++)
	{
		TableArray[i][i] = i;
	}
	
	for (size_t i = 0; i<8; i++)
	{
		for (size_t j = 0; j<8; j++)
		{
			std::cout << TableArray[i][j] << " ";
			if ( j == 7) std::cout << std::endl;
		}
		if ( i == 7) std::cout << std::endl;
	}
//=========================END Test Block 1 - Delete later=============================================================
	
	return 0;
}