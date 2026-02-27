#include <iostream>
using namespace std;

const int range = 14;
int binary[range];
int digit[16];

void setBinary(void)
{
	binary[0] = 1;
	binary[1] = 2;
	for(int i = 2; i < range; i++)
	{
		binary[i] = binary[i-1] * 2;
	}
}


//	hex number -> bunary 1 count
void setDigit(void)
{
	/*
	0000
	0001
	0010
	0011
	0100
	0101
	0110
	0111
	
	1000
	1001
	1010
	1011
	1100
	1101
	1110
	1111
	*/
	
	digit[0] = 0;
	digit[1] = 1;
	digit[2] = 1;
	digit[3] = 2;
	digit[4] = 1;
	digit[5] = 2;
	digit[6] = 2;
	digit[7] = 3;
	
	digit[8] = 1;
	digit[9] = 2;
	digit[10] = 2;
	digit[11] = 3;
	digit[12] = 2;
	digit[13] = 3;
	digit[14] = 3;
	digit[15] = 4;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setBinary();
	setDigit();
	
	int n, n_copy;
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		cin >> n;
		n_copy = n;
		
		int count = 0;
		for(int i = range-1; i >= 0; i--)
		{
			if(n >= binary[i]){
				n -= binary[i];
				count++;
				if(n == 0)	break;
			}
		}
		
		cout << count << " ";	// output binary count
		
		
		count = 0;
		while(n_copy > 0){
			count += digit[n_copy % 10];
			n_copy /= 10;
		}
	
		cout << count << '\n';	//output hex count
	}
	return 0;
}
