#include <iostream>
using namespace std;

int arr[105];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	
	int size;
	int test_case = 0;
	while(cin >> size)
	{
		test_case++;
		
		bool number[20005] = {false};	// detect the adding number is unique or not
		int n;	// input number
		bool isB2 = true;	// Flag: The sequence is B2-sequence or not
		
		cin >> arr[0];
		number[ arr[0] + arr[0] ] = true;
		if(arr[0] <= 0) isB2 = false;
		
		for(int i = 1; i < size; i++){
			cin >> n;
			
			if(!isB2) continue;
			else if(n <= arr[i-1]){
				isB2 = false;
				continue;
			}
			
			arr[i] = n;
			for(int j = 0; j <= i; j++){
				if(number[n + arr[j]] == true){
					isB2 = false;
					break;
				}
				
				number[n + arr[j]] = true;
			}
		}
		
		if(isB2)	cout << "Case #" << test_case << ": It is a B2-Sequence.\n\n";
		else		cout << "Case #" << test_case << ": It is not a B2-Sequence.\n\n";
	}
	return 0;
}
