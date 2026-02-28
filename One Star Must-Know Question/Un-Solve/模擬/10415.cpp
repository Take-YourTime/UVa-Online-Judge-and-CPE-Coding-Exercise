#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;
	cin.ignore();
	
	while(test_case)
	{
		string str;
		getline(cin, str);
		
		//	special case
		if(str.size() == 0)
		{
			cout << "0 0 0 0 0 0 0 0 0 0\n";
			test_case--;
			continue;
		}
		
		int finger[11] = {0};
		bool last[11] = {false};
		bool now[11] = {false};
		
		//	initialization
		for(int i = 0; i < 11; i++)
			last[i] = now[i] = false;
		
		for(int i = 0; i < str.size(); i++)
		{
			switch(str[i])
			{
				case 'c':{
					now[2] = now[3] = now[4] = true;
					now[7] = now[8] = now[9] = now[10] = true;
					break;
				}
				case 'd':{
					now[2] = now[3] = now[4] = true;
					now[7] = now[8] = now[9] = true;
		
					break;
				}
				case 'e':{
					now[2] = now[3] = now[4] = true;
					now[7] = now[8] = true;
					break;
				}
				case 'f':{
					now[2] = now[3] = now[4] = true;
					now[7] = true;
					break;
				}
				case 'g':{
					now[2] = now[3] = now[4] = true;
					break;
				}
				case 'a':{
					now[2] = now[3] = true;
					break;
				}
				case 'b':{
					now[2] = true;
					break;
				}
				case 'C':{
					now[3] = true;
					break;
				}
				case 'D':{
					now[1] = now[2] = now[3] = now[4] = true;
					now[7] = now[8] = now[9] = true;
					break;
				}
				case 'E':{
					now[1] = now[2] = now[3] = now[4] = true;
					now[7] = now[8] = true;
					break;
				}
				case 'F':{
					now[1] = now[2] = now[3] = now[4] = true;
					now[7] = true;
					break;
				}
				case 'G':{
					now[1] = now[2] = now[3] = now[4] = true;
					break;
				}
				case 'A':{
					now[1] = now[2] = now[3] = true;
					break;
				}
				case 'B':{
					now[1] = now[2] = true;
					break;
				}
				default:
					cout << str[i] << " is a wrong character!\n";
					exit(EXIT_FAILURE);
			}
			
			for(int i = 1; i <= 10; i++)
			{
				if(last[i] == false && now[i] == true)
					finger[i]++;
					
				//	reset element
				last[i] = false;
			}
			
			swap(now, last);
		}
			
		for(int i = 1; i <= 9; i++)
			cout << finger[i] << " ";
		cout << finger[10] << '\n';
		
		test_case--;
	}
	return 0;
}
