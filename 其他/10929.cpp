#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	string str;
	while(cin >> str)
	{
		if(str == "0") break;
		
		int sum = 0;
		
		for(int i = 0; i < str.size(); i+=2)
		{
			sum += str[i] - '0';
			if(i+1 >= str.size()) break;
			sum -= str[i+1] - '0';
		}
		
		if(sum % 11 == 0) 	cout << str << " is a multiple of 11.\n";
		else 			cout << str << " is not a multiple of 11.\n";
	}
	return 0;
}
