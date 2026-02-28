#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	long long int people;
	long long int date;
	
	while(cin >> people >> date)
	{
		
		// use formula of quadratic equation
		double end = (-1 + sqrt(1 + (people * (people-1) + date * 2) * 4 ) ) / 2 ;
		
		// check the answer has number after point or not
		if(end - int(end) == 0)		cout << int(end) << '\n'; // no number
		else 						cout << int(end) + 1 << '\n';	// has number after point
		
		
		
		//	This is another way to solve this problem, 
		//	which is easy to understand,
		//	but it costs much more, O(n).
		/*
		long long int current = 1;
		while(current <= date)
		{
			current += people;
			people++;
		}
		cout << people-1 << '\n';
		*/
	}
	return 0;
}
