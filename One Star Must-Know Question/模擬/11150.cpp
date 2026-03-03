#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int n;
	int drink;
	while(cin >> n)
	{
		drink = n;
		while(n >= 3){
			n -= 2; // -3+1
			drink++;
		}
		
		// two bottle left -> borrow one and get one more
		if(n  == 2) drink++;
		
		cout << drink << '\n';
	}
	return 0;
}
