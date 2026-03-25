#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(const int& a, const int& b){
	return abs(a) < abs(b);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int size;
	int n; // input buffer
	int testCase;
	vector<int> floors;
	
	floors.reserve(500005);
	
	
	cin >> testCase;
	while(testCase--)
	{
		floors.clear();
		
		cin >> size;
		
		// special case
		if(size == 0){
			cout << 0 << '\n';
			continue;
		}
		
		// input floors area
		while(size--){
			cin >> n;
			floors.push_back(n);
		}
	
		
		// sort absolute value in floors, small to big
		sort(floors.begin(), floors.end(), cmp);
		
		
		bool isPositive = (floors[0] > 0) ? true : false;
		int height = 1;
		
		for(int i = 1; i < floors.size(); i++){
			if(isPositive && floors[i] < 0){
				height++;
				isPositive = false;
			}
			else if(!isPositive && floors[i] > 0){
				height++;
				isPositive = true;
			}
		}
		
		cout << height << '\n';
	}
	return 0;
}
