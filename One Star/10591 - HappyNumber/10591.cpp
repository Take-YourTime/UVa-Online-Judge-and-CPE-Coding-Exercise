#include <iostream>
#include <map>
using namespace std;

int isHappy[1000] = {0};	// record the number is happy or not
							// 0: not meet  1: is happy  -1: is unhappy




// get digit square sum of integer n
int getDigitSquare(int n)
{
	int sum = 0;
	int digit;
	
	while(n > 0){
		digit = n % 10;
		n /= 10;
		sum += digit * digit;
	}
	
	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int n, nRecord;
	int testCase;
	map<int, bool> dictionary; // the number has meet in a sequence of calculate digit square
	
	isHappy[0] = -1;
	isHappy[1] = 1;
	
	cin >> testCase;
	for(int index = 1; index <= testCase; index++)
	{
		dictionary.clear();
		
		cin >> n;
		
		nRecord = n; // store value of n
		
		// detect n is happy number or not
		n = getDigitSquare(n);
		while(dictionary.find(n) == dictionary.end() && n != 1)
		{
			if(isHappy[n] == 1){
				n = 1;
				break;
			}
			else if(isHappy[n] == -1){
				break;
			}
			
			dictionary[n] = true;
			n = getDigitSquare(n);
		}
		
		
		cout << "Case #" << index << ": " << nRecord;
		if(n == 1){
			cout << " is a Happy number.\n";
			
			// record the calculation process numbers,
			// all of them are happy number
			for(auto it : dictionary){
				isHappy[it.first] = 1;
			}
		}
		else{
			cout << " is an Unhappy number.\n";
			
			// record the calculation process numbers,
			// all of them are unhappy number
			for(auto it : dictionary){
				isHappy[it.first] = -1;
			}
		}
		
	}
	return 0;
}
