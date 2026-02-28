#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int v, t;
	while(cin >> v >> t)
	{
		cout << v * t * 2 << '\n';
	}
	return 0;
}
