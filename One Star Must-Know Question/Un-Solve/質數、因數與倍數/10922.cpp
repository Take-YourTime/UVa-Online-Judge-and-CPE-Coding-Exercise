#include <iostream>
#include <string>

using namespace std;

long long int plus_sequence(long long int n)
{
	int plus = 0;
	
	while(n > 0)
	{
		plus += n % 10;
		n /= 10;
	}
	
	return plus;
}

int main()
{
	string str;
	
	while( getline(cin, str) )
	{
		if(str[0] == '0' && str.size() == 1)
			break;
		int n = 0;
		int degree = 1;
		
		for(int i = 0; i < str.size(); i++)
			n += int(str[i] - '0');
		
		while(n >= 10)
		{
			n = plus_sequence(n);
			degree++;
		}
		
		if(n % 9 == 0)
			cout << str << " is a multiple of 9 and has 9-degree " << degree << ".\n";
		else
			cout << str << " is not a multiple of 9.\n";
	}
	return 0;
}
