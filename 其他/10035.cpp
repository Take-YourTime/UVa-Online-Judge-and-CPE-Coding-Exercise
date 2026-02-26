#include <iostream>
#include <string>
using namespace std;



int main()
{
	string a, b; // use string to store the input number
	
	while(cin >> a >> b)
	{
		//	end program
		if(a == "0" && b == "0") break;
		
		int carryCount = 0;
		int carry = 0; 		// the carry of addition
		int digit1, digit2;	// digit of a and b
		
		//	add two number, and count the carry operation
		while(a.length() > 0 && b.length() > 0)
		{
			digit1 = a[a.size()-1] - '0';
			digit2 = b[b.size()-1] - '0';
			carry = (digit1 + digit2 + carry) / 10;
			if(carry > 0) carryCount++;
			
			a.pop_back(); b.pop_back();
		}
		
		//	handle the rest addition when the carry is not zero
		while(a.length() > 0 && carry > 0)
		{
			digit1 = a[a.size()-1] - '0';
			carry = (digit1 + carry) / 10;
			if(carry > 0) carryCount++;
			
			a.pop_back();
		}
		while(b.length() > 0 && carry > 0)
		{
			digit2 = b[b.size()-1] - '0';
			carry = (digit2 + carry) / 10;
			if(carry > 0) carryCount++;
			
			b.pop_back();
		}
		
		//	output
		if(carryCount == 0) 		cout << "No carry operation.\n";
		else if(carryCount == 1)	cout << "1 carry operation.\n";
		else						cout << carryCount << " carry operations.\n";
	}
	return 0;
}
