#include <iostream>
using namespace std;

int area[1005] = {0}; // block area

// set up all the method to stack a rectangle
// and calculate their area
void setBlocks(void)
{
	int mul;
	for(int i = 1; i <= 1000; i++){
		for(int j = 1; j <= 1000/i; j++){
			for(int k = 1; k <= 1000 / (i*j); k++){
				mul = (i * j + i * k + j * k) * 2;
				
				if(area[i*j*k] == 0) area[i*j*k] = mul;
				else if(mul < area[i*j*k]) area[i*j*k] = mul;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setBlocks();
	
	int n;
	int testCase;
	cin >> testCase;
	while(testCase--)
	{
		cin >> n;
		cout << area[n] << '\n';
	}
	return 0;
}
