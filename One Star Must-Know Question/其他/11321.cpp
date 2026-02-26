#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
	odd < even
	big odd < small odd
	small even < big even
*/

vector<int> list[10005];
vector<int> negative_list[10005];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int numbers, key;
	int n; // input number
	
	while(cin >> numbers >> key)
	{
		cout << numbers << " " << key << '\n';
		if(numbers == 0 && key == 0)	break;
		
		// initialization
		for(int i = 0; i < 10000; i++){
			list[i].clear();
			negative_list[i].clear();
		}
		
		// input and store in bucket with index: n%key
		while(numbers){
			numbers--;
			cin >> n;
			
			// classfy negative number and non-nagative number
			if(n > 0 || n % key == 0)	list[ n%key ].push_back(n);
			else						negative_list[ ~(n%key) ].push_back(n);
		}
		
		
		// negative bucket
		for(int index = key-1; index >= 0; index--){
			// Introsort ( buttleneck: O(nlogn) )
			sort(negative_list[index].begin(), negative_list[index].end());
			
			// output big odd number first
			for(int i = negative_list[index].size()-1; i >= 0; i--){
				if(negative_list[index][i] % 2 != 0) cout << negative_list[index][i] << '\n';
			}
			// output small even number first
			for(int i = 0; i < negative_list[index].size(); i++){
				if(negative_list[index][i] % 2 == 0) cout << negative_list[index][i] << '\n';
			}
		}
		
		
		// non-negative bucket;
		for(int index = 0; index < key; index++){
			// quick sort
			sort(list[index].begin(), list[index].end());
			
			// output big odd number first
			for(int i = list[index].size()-1; i >= 0; i--){
				if(list[index][i] % 2 != 0) cout << list[index][i] << '\n';
			}
			// output small even number first
			for(int i = 0; i < list[index].size(); i++){
				if(list[index][i] % 2 == 0) cout << list[index][i] << '\n';
			}
		}
	}
	return 0;
}
