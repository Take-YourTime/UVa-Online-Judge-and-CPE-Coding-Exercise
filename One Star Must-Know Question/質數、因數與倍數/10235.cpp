#include <iostream>
#include <cmath>
using namespace std;

const int range = 1000005;

bool composite[range] = {false}; // composite number list, true -> composite, false -> prime

void setPrimeList(void){
	composite[0] = true;
	composite[1] = true;
	for(int i = 2; i <= sqrt(range); i++){
		if(composite[i] == false){
			// i is prime
			for(int j = i; j <= (range-1)/i; j++){
				// i * j is composite
				composite[i * j] = true;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setPrimeList();
	
	int n;
	int nReverse;
	int nTemp;
	while(cin >> n)
	{
		nTemp = n;
		nReverse = 0;
		while(nTemp > 0){
			nReverse *= 10;
			nReverse += nTemp % 10;
			nTemp /= 10;
		}
		
		if(composite[n] == false){
			if(composite[nReverse] == false && nReverse != n){
				// To be an emirp, nReverse shouldn't be the same to n
				cout << n << " is emirp.\n";
			}
			else{
				cout << n << " is prime.\n";
			}
		}
		else{
			cout << n << " is not prime.\n";
		}
	}
	return 0;
}
