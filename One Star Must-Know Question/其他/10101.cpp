#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string type[10] = {	"",			
					"shata",	// 100 = 	10^2
					"hajar",	// 1000 = 	10^3
					"lakh",		// 100000 = 10^5
					"kuti",		// 10000000 = 10^7
					"shata",
					"hajar",
					"lakh",
					"kuti"};
					
long long int divide[10] = {100,	
							10,
							100,
							100,
							100,
							10,
							100,
							100,
							100,
							10};
							
							

int main()
{	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);

	long long int n;
	int testCase = 1;
	while(cin >> n)
	{
		// head of output
		cout << setw(4) << testCase << ".";
		testCase++;
		
		if(n < 100){
			// n is small -> output directly
			cout << " " << n << '\n';
			continue;
		}
		
		// initialization
		long long int coef[10] = {0};
		int index = 0;
		bool isKuti = (n >= 10000000) ? true : false;
		
		// calculate the coefficients
		while(n > 0){
			coef[index] = n % divide[index];
			n /= divide[index];
			index++;
		}
		
		// bigger than kuti
		for(int i = 9; i >= 5; i--){
			if(coef[i] != 0){
				cout << " " << coef[i] << " " << type[i];
			}
		}
		
		// kuti
		if(coef[4] != 0){ cout << " " << coef[4]; }
		if(isKuti){ cout << " " << type[4]; }
		
		// smaller than kuti
		for(int i = 3; i >= 1; i--){
			if(coef[i] != 0){
				cout << " " << coef[i] << " " << type[i];
			}
		}
		
		// constant
		if(coef[0] != 0){
			cout << " " << coef[0];
		}
		cout << '\n';
	}
	return 0;
}
