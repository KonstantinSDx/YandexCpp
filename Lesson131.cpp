#include <iostream>


class Fraction
{
    int Chislitel = 0;
	int Znamenatel = 1;
	
	public:
	Fraction (int Chis = 0, int Znam = 1 ) : Chislitel(Chis), Znamenatel(Znam) 
	{
		
	}	
	
	void reduce()
	{
		int Count =2;
		int Min = 0;
		if (Chislitel <= Znamenatel) Min = Chislitel;
		else Min = Znamenatel;
        while (Count<=Min)
		{
           if (Chislitel%Count==0 && Znamenatel%Count==0 )
           {
           	  Chislitel = Chislitel / Count; 
           	  Znamenatel = Znamenatel  / Count;
           }
		   else Count++;
		}
	}
	
	void print()
	{
		reduce();
		std::cout << Chislitel << "/" << Znamenatel << std::endl; 
	} 
		
	friend Fraction operator*(const Fraction &Fr1, const Fraction &Fr2);
	friend Fraction operator*(const int NumX, const Fraction &Fr2);
	friend Fraction operator*(const Fraction &Fr1, const int NumX);
	friend std::ostream& operator<< (std::ostream &OutLine, const Fraction &FrStream);
	friend std::istream& operator>> (std::istream &IntoLine, Fraction &FrStream);
	
	 	
};

Fraction operator* (const Fraction &Fr1, const Fraction &Fr2)
{
	return Fraction( Fr1.Chislitel*Fr2.Chislitel, Fr1.Znamenatel*Fr2.Znamenatel);
}

Fraction operator* (const int NumX, const Fraction &Fr2)
{
	return Fraction( NumX*Fr2.Chislitel, Fr2.Znamenatel);
}

Fraction operator* (const Fraction &Fr1, const int NumX)
{
	return Fraction( Fr1.Chislitel*NumX, Fr1.Znamenatel);
}

std::ostream& operator<< (std::ostream &OutLine, const Fraction &FrStream)
{
	OutLine << FrStream.Chislitel << "/" << FrStream.Znamenatel;
	return  OutLine;
}

std::istream& operator>> (std::istream &IntoLine, Fraction &FrStream)
{
	char Temp;
	IntoLine >> FrStream.Chislitel;
	IntoLine >> Temp;
	IntoLine >> FrStream.Znamenatel;
	return IntoLine; 
}

int main()
{

    Fraction f1(3, 4);
    f1.print();
 
    Fraction f2(2, 7);
    f2.print();
 
    Fraction f3 = f1 * f2;
    f3.print();
 
    Fraction f4 = f1 * 3;
    f4.print();
 
    Fraction f5 = 3 * f2;
    f5.print();
 
    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    Fraction f7;
	std::cout << "Enter fraction 1: ";
	std::cin >> f7;
 
	Fraction f8;
	std::cout << "Enter fraction 2: ";
	std::cin >> f8;
 
	std::cout << f7 << " * " << f8 << " is " << f7 * f8 << '\n';
	
}
