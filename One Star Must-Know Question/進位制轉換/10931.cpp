#include <iostream>
#include <cmath>
using namespace std;


const int range = 40;
long long int binary[range];

void setBinary(void)
{
	binary[0] = 1;
	binary[1] = 2;
	for(int i = 2; i < range; i++){
		binary[i] = binary[i-1] * 2;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setBinary();
	
	long long int n;
	while(cin >> n && n != 0)
	{
		cout << "The parity of ";
		
		int count = 0;
		
		// strat form log_2(n)
		for(int i = int(log(n)/log(2)); i >= 0; i--){
			if(n >= binary[i]){
				n -= binary[i];
				count++;
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		
		cout << " is " << count << " (mod 2).\n";
	}
	return 0;
}
