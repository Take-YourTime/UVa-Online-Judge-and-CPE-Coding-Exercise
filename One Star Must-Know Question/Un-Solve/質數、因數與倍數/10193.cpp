#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//	這題考找最大公因數

int gcd(int a, int b)
{
	if(a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int main()
{
	int test_case;
	cin >> test_case;
	cin.ignore();
	
	for(int test = 1; test <= test_case; test++)
	{
		string str1, str2;
		
		//	input
		getline(cin, str1);
		getline(cin, str2);
		if(str1[0] == '0' || str2[0] == '0' || str1.size() == 1 || str2.size() == 1)
		{
			cout << "Pair #" << test << ": Love is not all you need!\n"; 
			continue;
		}
		
		int num1 = 0, num2 = 0;
		
		//	turn the binary number into decimal number
		for(int i = 0; i < str1.size(); i++)
		{
			if(str1[i] == '1')
				num1 += pow(2, ( str1.size() - 1 - i ) );
		}
		
		for(int i = 0; i < str2.size(); i++)
		{
			if(str2[i] == '1')
				num2 += pow(2, ( str2.size() - 1 - i ) );
		}
		
		//	找兩個數字的最大公因數
		//	最大公因數大於1 → Both are made of love.
		if(gcd(num1, num2) > 1)
			cout << "Pair #" << test << ": All you need is love!\n";
		else
			cout << "Pair #" << test << ": Love is not all you need!\n"; 
	}
	return 0;
}
