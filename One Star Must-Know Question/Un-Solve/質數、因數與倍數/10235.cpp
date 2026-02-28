#include <iostream>
#include <cmath>
#define PRIME_RANGE 1000000
using namespace std;

bool* prime;

int main()
{
	//	build prime list
	prime = new bool[PRIME_RANGE];
	for(int i = 0; i < PRIME_RANGE; i++)
		prime[i] = true;
		
	prime[0] = false;
	prime[1] = false;
	
	for(int i = 2; i < sqrt(PRIME_RANGE); i++)
	{
		if( prime[i] )
			for(int j = (PRIME_RANGE - 1) / i; j >= i; j--)
				if( prime[j] )
					prime[i * j] = false;
	}
	
	//	the input number
	int n;
	
	while( cin >> n && ( !cin.eof() ) )
	{
		//	the reverse of n
		int n_re = 0;
		
		//	use for get n_re
		int n_temp = n;
		
		while(n_temp > 0)
		{
			n_re *= 10;
			n_re += n_temp % 10;
			n_temp /= 10;
		}
		
		if( prime[n] )
		{
			if( prime[n_re] && n_re != n)
				cout << n << " is emirp.\n";
			else
				cout << n << " is prime.\n";
		}
		else
			cout << n << " is not prime.\n";
	}
	
	delete[] prime;
	return 0;
}
