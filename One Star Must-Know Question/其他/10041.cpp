#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int list[505];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int house;
	int test_case;
	cin >> test_case;
	while(test_case--){
		
		cin >> house;
		for(int i = 0; i < house; i++){
			cin >> list[i];
		}
		
		sort(list, list + house);
		
		int mid = list[ (house-1)/2 ];
		int sum = 0;
		
		for(int i = 0; i < house; i++){
			sum += abs(mid - list[i]);
		}
		
		cout << sum << '\n';
	}
	return 0;
}
