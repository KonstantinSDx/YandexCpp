#include <iostream>
#include <numeric>

class Rational
{
	private:
	int m_Numerator;
	unsigned int m_Denominator;
	
	public:
	Rational (int c_Numerator = 0, int c_Denominator = 1)
	{
		int m_NOD = std::gcd(c_Numerator, c_Denominator);
		m_Numerator = c_Numerator / m_NOD;
		m_Denominator = c_Denominator / m_NOD; 
	}
	
	int Numerator() const
	{
		return m_Numerator; 
	} 
	
	int Denominator() const
	{
		return m_Denominator;
	}
	
	Rational operator+()
	{		
		return Rational(m_Numerator, m_Denominator);
	}

	Rational operator-()
	{		
		return Rational(-m_Numerator, m_Denominator);
	}
	
	friend bool operator== (const Rational &rt1, const Rational &rt2);
	friend bool operator!= (const Rational &rt1, const Rational &rt2);
	friend void operator+= ( Rational &rt1, const Rational &rt2);
	friend void operator-= ( Rational &rt1, const Rational &rt2);
	friend void operator*= ( Rational &rt1, const Rational &rt2);
	friend void operator/= ( Rational &rt1, const Rational &rt2);
	friend Rational operator+ (const Rational &rt1, const Rational &rt2);
	friend Rational operator- (const Rational &rt1, const Rational &rt2);	
	friend Rational operator* (const Rational &rt1, const Rational &rt2);
	friend Rational operator/ (const Rational &rt1, const Rational &rt2);

};

	
	Rational operator+ (const Rational &rt1, const Rational &rt2)
	{
		int NumeratorX;
		unsigned int DenominatorX;	
		NumeratorX = rt1.m_Numerator*rt2.m_Denominator + rt2.m_Numerator*rt1.m_Denominator;
		DenominatorX = rt1.m_Denominator*rt2.m_Denominator;
		return Rational(NumeratorX, DenominatorX);
	}

	Rational operator- (const Rational &rt1, const Rational &rt2)
	{
		int NumeratorX;
		unsigned int DenominatorX;	
		NumeratorX = rt1.m_Numerator*rt2.m_Denominator - rt2.m_Numerator*rt1.m_Denominator;
		DenominatorX = rt1.m_Denominator*rt2.m_Denominator;
		return Rational( NumeratorX,DenominatorX);
	}
	
	Rational operator* (const Rational &rt1, const Rational &rt2)
	{
		int NumeratorX;
		unsigned int DenominatorX;	
		NumeratorX = rt1.m_Numerator*rt2.m_Numerator;
		DenominatorX = rt1.m_Denominator*rt2.m_Denominator;
		return Rational(NumeratorX, DenominatorX);
	}
	
	Rational operator/ (const Rational &rt1, const Rational &rt2)
	{
		int NumeratorX;
		unsigned int DenominatorX;	
		NumeratorX = rt1.m_Numerator*rt2.m_Denominator;
		DenominatorX = rt1.m_Denominator*rt2.m_Numerator;
		return Rational(NumeratorX, DenominatorX);
	}


	void operator+= ( Rational &rt1, const Rational &rt2)
	{
		rt1.m_Numerator = rt1.m_Numerator*rt2.m_Denominator + rt2.m_Numerator*rt1.m_Denominator;
		rt1.m_Denominator = rt1.m_Denominator*rt2.m_Denominator;
		int NOD = std::gcd(rt1.m_Numerator, rt1.m_Denominator);
		rt1.m_Numerator = rt1.m_Numerator / NOD;
		rt1.m_Denominator = rt1.m_Denominator / NOD;	
	}
	
	void operator-= ( Rational &rt1, const Rational &rt2)
	{
		rt1.m_Numerator = rt1.m_Numerator*rt2.m_Denominator - rt2.m_Numerator*rt1.m_Denominator;
		rt1.m_Denominator = rt1.m_Denominator*rt2.m_Denominator;
		int NOD = std::gcd(rt1.m_Numerator, rt1.m_Denominator);
		rt1.m_Numerator = rt1.m_Numerator / NOD;
		rt1.m_Denominator = rt1.m_Denominator / NOD;	
	}
	
	void operator*= ( Rational &rt1, const Rational &rt2)
	{
		rt1.m_Numerator = rt1.m_Numerator*rt2.m_Numerator;
		rt1.m_Denominator = rt1.m_Denominator*rt2.m_Denominator;
		int NOD = std::gcd(rt1.m_Numerator, rt1.m_Denominator);
		rt1.m_Numerator = rt1.m_Numerator / NOD;
		rt1.m_Denominator = rt1.m_Denominator / NOD;	
	}
	
	void operator/= ( Rational &rt1, const Rational &rt2)
	{
		rt1.m_Numerator = rt1.m_Numerator*rt2.m_Denominator;
		rt1.m_Denominator = rt1.m_Denominator*rt2.m_Numerator;
		int NOD = std::gcd(rt1.m_Numerator, rt1.m_Denominator);
		rt1.m_Numerator = rt1.m_Numerator / NOD;
		rt1.m_Denominator = rt1.m_Denominator / NOD;	
	}

	bool operator== (const Rational &rt1, const Rational &rt2)
	{
		if ( ( rt1.m_Numerator == rt2.m_Numerator ) && ( rt1.m_Denominator == rt2.m_Denominator ) ) return true;
		else return false;
	}
	
	bool operator!= (const Rational &rt1, const Rational &rt2)
	{
		if ( ( rt1.m_Numerator != rt2.m_Numerator ) || ( rt1.m_Denominator != rt2.m_Denominator ) ) return true;
		else return false;
	}
	


int main()
{
	Rational Drob1(5, 12);  //   5  8   2
	Rational Drob2(8, 15);  //  12  15  3
	Rational Drob3(2, 3);
	Drob1 += Drob2;
	std::cout << "Numerator Drob1 - " << Drob1.Numerator() << ".   Denominator Drob1 - " << Drob1.Denominator() << std::endl;
	Rational Drob4 = Drob2 + Drob3;
	std::cout << "Numerator Drob4 : " << Drob4.Numerator() << ".   Denominator Drob4 : " << Drob4.Denominator() << std::endl;
	return 0;
}