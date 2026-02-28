#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	
	int test_case;
	cin >> test_case;
	for(int index = 1; index <= test_case; index++)
	{
		int a, b;
		cin >> a >> b;
		if(a > b)	swap(a, b);
		if(a % 2 == 0)	a++;
		if(b % 2 == 0)	b--;

		if(a <= b)		cout << "Case " << index << ": " << (b+a) * ((b - a) / 2 + 1) / 2 << '\n';
		else	cout << "Case " << index << ": " << 0 << '\n';
	}
	return 0;
}
