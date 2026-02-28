#include <iostream>
using namespace std;

bool squareNumber[110000] = {false};

int main()
{
	for(int i = 1; i <= 320; i++){
		squareNumber[i*i] = true;
	}
	
	int left, right;
	while(cin >> left >> right && left != 0 && right != 0)
	{
		int count = 0;
		while(left <= right){
			if(squareNumber[left])	count++;
			left++;
		}
		
		cout << count << '\n';
	}
	return 0;
}
