#include <iostream>
#include <string>
using namespace std;

int main()
{
	//		6(bottom)
	//		2
	//	3	1	4
	//		5	
	int times;
	
	while(cin >> times && (times != 0) )
	{
		cin.ignore();
		string str;
		
		int die[6] = {0};
		
						die[0] = 6; // (bottom)
						die[1] = 2;
		die[4] = 3;		die[2] = 1;		die[5] = 4;
						die[3] = 5;
		
		while(times)
		{
			getline(cin, str);
			switch(str[0])
			{
				case 'n':{
					int temp = die[0];
					die[0] = die[1];
					die[1] = die[2];
					die[2] = die[3];
					die[3] = temp;
					break;
				}
				case 's':{
					int temp = die[3];
					die[3] = die[2];
					die[2] = die[1];
					die[1] = die[0];
					die[0] = temp;
					break;
				}
				case 'e':{
					int temp = die[5];
					die[5] = die[2];
					die[2] = die[4];
					die[4] = die[0];
					die[0] = temp;
					break;
				}
				case 'w':{
					int temp = die[4];
					die[4] = die[2];
					die[2] = die[5];
					die[5] = die[0];
					die[0] = temp;
					break;
				}
				default:
					cout << str[0] << " is wrong character!\n";
					exit(EXIT_FAILURE);
			}
			times--;
		}
		
		cout << die[2] << '\n';
	}
	return 0;
}
