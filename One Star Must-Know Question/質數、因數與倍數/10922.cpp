#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	string str;
	
	while(cin >> str && str != "0")
	{
		int degree = 1;
		int sum = 0;
		
		// sum up the digits in str
		for(char ch : str){
			sum += ch-'0';
		}
		
		do{
			if(sum == 9){
				cout << str << " is a multiple of 9 and has 9-degree " << degree << ".\n";
				break;
			}
			else if(sum % 9 == 0){
				degree++;
			}
			else{
				cout << str << " is not a multiple of 9.\n";
				break;
			}
			
			// sum up all the digits of "sum"
			int sumTemp = 0; // calculate buffer
			while(sum > 0){
				sumTemp += sum % 10;
				sum /= 10;
			}
			sum = sumTemp;
		}while(true);
	}
	return 0;
}
