#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int test_case;
	cin >> test_case;
	while(test_case){
		test_case--;
		
		int house;
		cin >> house;
		vector<int> list;
		
		int n;
		
		for(int i = 0; i < house; i++){
			cin >> n;
			list.push_back(n);
		}
		
		sort(list.begin(), list.end());
		
		int mid = list[ (list.size()-1)/2 ];
		int sum = 0;
		
		for(int pos : list){
			sum += abs(mid - pos);
		}
		
		cout << sum << '\n';
	}
	return 0;
}
