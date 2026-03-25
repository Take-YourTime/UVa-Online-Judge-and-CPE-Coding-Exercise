#include <iostream>
#include <map>
using namespace std;

bool isHappy[1000000000] = {false}; // the number is happy or not
// we can also record the unhappy number here

map<int, bool> dictionary;


// get digit power sum of integer n
int getDigitPower(int n)
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
	
	
	cin >> testCase;
	for(int index = 1; index <= testCase; index++)
	{
		dictionary.clear();
		
		cin >> n;
		
		nRecord = n; // store value of n
		
		// detect n is happy number or not
		n = getDigitPower(n);
		while(dictionary.find(n) == dictionary.end() && n != 1)
		{
			if(isHappy[n]){
				n = 1;
				break;
			}
			
			dictionary[n] = true;
			n = getDigitPower(n);
		}
		
		
		cout << "Case #" << index << ": " << nRecord;
		if(n == 1){
			cout << " is a Happy number.\n";
			
			// record the calculation process numbers,
			// all of them are happy number
			for(auto it : dictionary){
				isHappy[it.first] = true;
			}
		}
		else{
			cout << " is an Unhappy number.\n";
		}
		
	}
	return 0;
}
