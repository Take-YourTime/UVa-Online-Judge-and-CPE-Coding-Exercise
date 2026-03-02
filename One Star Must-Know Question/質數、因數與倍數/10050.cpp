#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int testCase;
	cin >> testCase;
	while(testCase--)
	{
		int day;		// total simulate days
		int party;		// political parties number
		int parameter;	// hartal parameter
		int count = 0;	// the number of hartal days
		bool hartal[3655] = {false};

		cin >> day >> party;
		while(party--){
			cin >> parameter;
			int date = parameter-1;
			while(date < day){
				if(hartal[date] == false && date % 7 < 5){
					hartal[date] = true;
					count++;
				}
				date += parameter;
			}
		}
		cout << count << '\n';
	}
	return 0;
}
