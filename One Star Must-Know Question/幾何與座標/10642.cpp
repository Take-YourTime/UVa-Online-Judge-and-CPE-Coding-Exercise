#include <iostream>
#include <cmath>
using namespace std;


int index[100005] = {0};



int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	for(int i = 1; i < 100005; i++){
		index[i] = index[i-1] + i;
	}
	
	int test_case;
	cin >> test_case;
	
	int a, b, c, d; // (a, b) -> (c, d)
	for(int i = 1; i <= test_case; i++)
	{
		cin >> a >> b >> c >> d;
		cout << "Case " << i << ": " << abs( (index[c+d] + c) - (index[a+b] + a) ) << '\n';
	}
	
	return 0;
}
