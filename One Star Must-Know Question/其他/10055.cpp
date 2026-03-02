#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	long long int a, b;
	
	while(cin >> a >> b) cout << abs(b-a) << '\n';
		
	return 0;
}
