#include <iostream>
#include <algorithm>
using namespace std;

int floors[500005];

inline int absolute(int x) { return x < 0 ? -x : x; }

bool cmp(const int a, const int b){
	return absolute(a) < absolute(b);
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int size;
	int testCase;
	
	cin >> testCase;
	while(testCase--)
	{
		cin >> size;
		
		// special case
		if(size == 0){
			cout << 0 << '\n';
			continue;
		}
		
		for(int i = 0; i < size; i++){
			cin >> floors[i];
		}
		
		// sort absolute value in floors, small to big
		sort(floors, floors+size, cmp);
		
		
		bool isPositive = (floors[0] > 0) ? true : false;
		int height = 1;
		
		for(int i = 1; i < size; i++){
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
