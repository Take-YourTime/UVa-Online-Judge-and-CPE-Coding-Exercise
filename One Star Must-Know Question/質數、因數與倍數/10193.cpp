#include <iostream>
#include <string>
using namespace std;

int binary[31];

void setBinaryList(void)
{
	binary[0] = 1;
	binary[1] = 2;
	for(int i = 2; i < 31; i++){
		binary[i] = binary[i-1] * 2;
	}
}

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

//	All you need is love! -> gcd(num1, num2) >= 2
//	So, turn the binary base number into decimal, and check their gcd()

int main()
{
	setBinaryList();
	
	string a, b;
	int testCase;
	cin >> testCase;
	for(int index = 1; index <= testCase; index++)
	{
		int num1 = 0, num2 = 0;
		cin >> a >> b;
		
		// turn num1 into decimal
		int size = a.size();
		for(int i = 0; i < size; i++){
			if(a[i] == '1')	num1 += binary[size - i - 1];
		}
		
		// turn num2 into decimal
		size = b.size();
		for(int i = 0; i < size; i++){
			if(b[i] == '1')	num2 += binary[size - i - 1];
		}
		
		
		// output
		cout << "Pair #" << index << ": ";
		if(gcd(num1, num2) != 1) cout << "All you need is love!\n";
		else cout << "Love is not all you need!\n";
	}
	return 0;
}
