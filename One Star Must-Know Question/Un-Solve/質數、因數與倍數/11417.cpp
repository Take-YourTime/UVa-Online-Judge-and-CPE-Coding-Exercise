#include <iostream>
using namespace std;

//	輾轉相除法
int gcd(int a, int b)
{
	if(a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int main()
{
	int n;
	
	while(cin >> n && n > 0)
	{
		int sum = 0;
		
		//	calculate
		for(int i = 1; i < n; i++)
		{
			for(int j = i+1; j <= n; j++)
				sum += gcd(i, j);
		}
		
		//	output
		cout << sum << '\n';
	}
	return 0;
}
