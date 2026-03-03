#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	string str;
	int testCase;
	cin >> testCase;
	cin.ignore();
	while(testCase--)
	{
		getline(cin, str);
		
		//	special case
		if(str.size() == 0)
		{
			cout << "0 0 0 0 0 0 0 0 0 0\n";
			continue;
		}
		
		bool last[11] = {false};
		bool current[11];
		int count[11] = {0};
		
		for(char ch : str) {
			switch(ch)
			{
				case 'c':{
					current[2] = current[3] = current[4] = current[7] = current[8] = current[9] = current[10] = true;
					current[1] = current[5] = current[6] = false;
					break;
				}
				case 'd':{
					current[2] = current[3] = current[4] = current[7] = current[8] = current[9] = true;
					current[1] = current[5] = current[6] = current[10] = false;
					break;
				}
				case 'e':{
					current[2] = current[3] = current[4] = current[7] = current[8] = true;
					current[1] = current[5] = current[6] = current[9] = current[10] = false;
					break;
				}
				case 'f':{
					current[2] = current[3] = current[4] = current[7] = true;
					current[1] = current[5] = current[6] = current[8] = current[9] = current[10] = false;
					break;
				}
				case 'g':{
					current[2] = current[3] = current[4] = true;
					current[1] = current[5] = current[6] = current[7] = current[8] = current[9] = current[10] = false;
					break;
				}
				case 'a':{
					current[2] = current[3] = true;
					current[1] = current[4] = current[5] = current[6] = current[7] = current[8] = current[9] = current[10] = false;
					break;
				}
				case 'b':{
					current[2] = true;
					current[1] = current[3] = current[4] = current[5] = current[6] = current[7] = current[8] = current[9] = current[10] = false;
					break;
				}
				case 'C':{
					current[3] = true;
					current[1] = current[2] = current[4] = current[5] = current[6] = current[7] = current[8] = current[9] = current[10] = false;
					break;
				}
				case 'D':{
					current[1] = current[2] = current[3] = current[4] = current[7] = current[8] = current[9] = true;
					current[5] = current[6] = current[10] = false;
					break;
				}
				case 'E':{
					current[1] = current[2] = current[3] = current[4] = current[7] = current[8] = true;
					current[5] = current[6] = current[9] = current[10] = false;
					break;
				}
				case 'F':{
					current[1] = current[2] = current[3] = current[4] = current[7] = true;
					current[5] = current[6] = current[8] = current[9] = current[10] = false;
					break;
				}
				case 'G':{
					current[1] = current[2] = current[3] = current[4] = true;
					current[5] = current[6] = current[7] = current[8] = current[9] = current[10] = false;
					break;
				}
				case 'A':{
					current[1] = current[2] = current[3] = true;
					current[4] = current[5] = current[6] = current[7] = current[8] = current[9] = current[10] = false;
					break;
				}
				case 'B':{
					current[1] = current[2] = true;
					current[3] = current[4] = current[5] = current[6] = current[7] = current[8] = current[9] = current[10] = false;
					break;
				}
				default:{
					break;
				}
			}
			
			for(int i = 1; i < 11; i++){
				if(current[i] != last[i]){
					if(current[i] == true) count[i]++;
					last[i] = current[i];
				}
			}
		}
		
		for(int i = 1; i < 10; i++){
			cout << count[i] << " ";
		}
		cout << count[10] << '\n';
	}
	return 0;
}
