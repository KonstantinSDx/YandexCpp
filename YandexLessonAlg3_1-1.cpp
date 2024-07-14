#include <iostream>

int main()
{
	int n=1;
	int k=1;
	int Res_n = 1;
	int Res_k = 1;
	int Res_n_k = 1;
	std::cin >> n >> k;
//	int Res_n_k = n-k;
	for (int i=0; i<n; i++)
	{
		Res_n = Res_n*(n-i);
		if (i<k) Res_k = Res_k*(k-i);
		if ( i < (n-k) ) Res_n_k = Res_n_k*( (n-k) - i );
	}
	
	std::cout << Res_n/(Res_k*Res_n_k);
	 
	return 0;
}