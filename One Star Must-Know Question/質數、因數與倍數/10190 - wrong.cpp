#include <iostream>
#include <cmath>
using namespace std;

const long double EPS = 1e-9;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	long long int number, key;
	while(cin >> number >> key)
	{
		if(number <= 1 || key <= 1 || number < key || number >= 2000000000 || key >= 2000000000)
		{
			cout << "Boring!" << endl;
			continue;
		}
		
		double logarithm = log(number) / log(key);
		//cout << "test: " << logarithm << " " << int(logarithm) << '\n';
		//cout << logarithm - int(logarithm) << '\n';
		if(logarithm - double(int(logarithm)) > 1e-9 ){
			cout << "Boring!\n";
			continue;
		}
		
		
		while(number >= 1){
			cout << number << " ";
			number /= key;
		}
		cout << '\n';
	}
	return 0;
}
