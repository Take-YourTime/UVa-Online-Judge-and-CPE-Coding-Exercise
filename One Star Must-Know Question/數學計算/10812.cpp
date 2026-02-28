#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int sum, gap;
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		cin >> sum >> gap;
		if(sum - gap < 0 || (sum - gap) % 2 != 0)	cout << "impossible\n";
		else	cout << (sum + gap) / 2 << " " << (sum-gap) / 2 << '\n';
	}
	return 0;
}
