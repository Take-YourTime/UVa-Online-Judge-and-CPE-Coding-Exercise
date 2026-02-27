#include <iostream>
using namespace std;

const int fib_range = 40;
int fib[fib_range];


// build Fibonaccimal sequences
void setFibSequence(void)
{
	fib[0] = 1;
	fib[1] = 2;
	for(int i = 2; i < fib_range; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setFibSequence();
	
	int test_case;
	cin >> test_case;
	int n;
	while(test_case--)
	{
		cin >> n;
		cout << n << " = ";
		
		int max = fib_range - 1;	// the index of max number of Fibonaccimal sequence that is smaller than n
		while(fib[max] > n){
			max--;
		}
		
		//	Since the Fibonaccimal base sequence of each number is unique,
		//	if the fib number is bigger than n, output 1 and make n = n - fib.
		//	Otherwise, output 0
		for(int i = max; i >= 0; i--)
		{
			if(n >= fib[i]){
				n -= fib[i];
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		
		cout << " (fib)\n";
	}
	
	return 0;
}
