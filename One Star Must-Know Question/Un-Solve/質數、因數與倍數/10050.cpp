#include <iostream>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;
	while(test_case)
	{
		//	input
		int days;
		cin >> days;
		bool* hartals = new bool[days + 1];
		for(int i = 0; i <= days; i++)
			hartals[i] = false;
		
		int p;
		cin >> p;
		int* party = new int[p];
		for(int i = 0; i < p; i++)
			cin >> party[i];
		
		//	calculate
		for(int i = 0; i < p; i++)
		{
			int h = party[i];
			
			while(h <= days)
			{
				hartals[ h ] = true;
				h += party[i];
			}
		}
		
		int Fri = 6, Sat = 7;
		while(Fri <= days)
		{
			hartals[ Fri ] = false;
			Fri += 7;
		}
		while(Sat <= days)
		{
			hartals[ Sat ] = false;
			Sat += 7;
		}
		
		//	output
		int count = 0;
		for(int i = 1; i <= days; i++)
		{
			if(hartals[i])
				count++;
		}
		cout << count << '\n';
		
		test_case--;
	}
	return 0;
}
