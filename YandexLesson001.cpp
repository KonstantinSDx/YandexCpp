#include <iostream>
#include <string>

int main ()
{
	std::string Str1, Str2, Str3, Str4, Str5;
	Str1 = "C++ is a general-purpose programming language with a bias towards systems programming that \n";
	Str2 = "- is a better C\n";
	Str3 = "- supports data abstraction\n";
	Str4 = "- supports object-oriented programming\n";
	Str5 = "- supports generic programming.\n";
	std::cout << Str1;
	std::cout << "  " << Str2;
	std::cout << "  " << Str3;
	std::cout << "  " << Str4;
	std::cout << "  " << Str5; 

    int Number1;
	int Number2;
	std::cin >> Number1;
	std::cin >> Number2;
	std::cout << Number1 + Number2 << "\n";
	   
	return 0;
}
