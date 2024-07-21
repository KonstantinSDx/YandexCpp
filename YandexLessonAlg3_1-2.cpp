#include <iostream>

int main()
{
	int n=1;
	int k=1;
	int Res_n = 1;
	int Res_k = 1;
	int Res_n_1 = 1;
	std::cin >> n >> k;
//	int Res_n_k = n-k;
	for (int i=0; i<(k+n-1); i++)
	{
		Res_n = Res_n*(k+n-1-i);
		if (i<k) Res_k = Res_k*(k-i);
		if ( i < (n-1) ) Res_n_1 = Res_n_1*( (n-1) - i );
	}
	
	std::cout << Res_n/(Res_k*Res_n_1);
	 
	return 0;
}