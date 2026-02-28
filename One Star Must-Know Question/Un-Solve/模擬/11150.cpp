#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n && (!cin.eof()) )
	{
		int count = n;
		
		while(n >= 3)
		{
			n = n-2;
			count++;
		}
		
		if(n == 2)
			count++;
			
		cout << count << '\n';
		
	}
	return 0;
}
