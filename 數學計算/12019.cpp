#include <iostream>
using namespace std;

int month[13];

void setMonth(void)
{
	month[0] = 0;
	month[1] = 0;
	month[2] = month[1] + 31;
	month[3] = month[2] + 28;
	month[4] = month[3] + 31;
	month[5] = month[4] + 30;
	month[6] = month[5] + 31;
	month[7] = month[6] + 30;
	month[8] = month[7] + 31;
	month[9] = month[8] + 31;
	month[10] = month[9] + 30;
	month[11] = month[10] + 31;
	month[12] = month[11] + 30;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setMonth();
	
	// 1/1 -> Saturday
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		int m, d; // month, date
		cin >> m >> d;
		 
		d = (d + month[m] + 6-1) % 7;
		
		switch(d)
		{
			case 1:{
				cout << "Monday\n";
				break;
			}
			case 2:{
				cout << "Tuesday\n";
				break;
			}
			case 3:{
				cout << "Wednesday\n";
				break;
			}
			case 4:{
				cout << "Thursday\n";
				break;
			}
			case 5:{
				cout << "Friday\n";
				break;
			}
			case 6:{
				cout << "Saturday\n";
				break;
			}
			case 0:{
				cout << "Sunday\n";
				break;
			}
			default:{
				break;
			}
		}
	}
	return 0;
}
