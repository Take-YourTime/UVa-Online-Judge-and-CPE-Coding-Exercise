#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int numbers;
	while(cin >> numbers)
	{
		for(int i = 0; i < numbers; i++){
			cin >> arr[i];
		}
		
		sort(arr, arr+numbers);
		
		int middle = (numbers-1) / 2;
		int key = arr[middle]; // middle point
		
		// get left bound
		int* left = lower_bound(arr, arr + middle, key);
		
		// get right bound
		int* right;
		if(numbers % 2 == 0) right = upper_bound(arr + middle + 1, arr + numbers, arr[middle+1]);
		else right = upper_bound(arr + middle, arr + numbers, arr[middle]);
		
		cout << key << " " << int(right - left) << " ";
		if(numbers % 2 == 0) cout << arr[middle+1] - arr[middle] + 1 << '\n';
		else cout << 1 << '\n';
	}
	return 0;
}

