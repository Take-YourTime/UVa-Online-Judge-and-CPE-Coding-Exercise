#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int step;
	string str;
	int die[6];
	while(cin >> step && step != 0)
	{
						die[0] = 6;
						die[2] = 2;
			die[3] = 3;	die[1] = 1;	die[4] = 4;
						die[5] = 5;
						
		while(step--)
		{
			cin >> str;
			switch(str[0])
			{
				case 'n':{
					int temp = die[0];
					die[0] = die[2];
					die[2] = die[1];
					die[1] = die[5];
					die[5] = temp;
					break;
				}
				case 'e':{
					int temp = die[4];
					die[4] = die[1];
					die[1] = die[3];
					die[3] = die[0];
					die[0] = temp;
					break;
				}
				case 's':{
					int temp = die[5];
					die[5] = die[1];
					die[1] = die[2];
					die[2] = die[0];
					die[0] = temp;
					break;
				}
				case 'w':{
					int temp = die[3];
					die[3] = die[1];
					die[1] = die[4];
					die[4] = die[0];
					die[0] = temp;
					break;
				}
				default:{
					break;
				}
			}
		}
		
		cout << die[1] << '\n';
	}
	return 0;
}
