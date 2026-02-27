#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int cost[36] = {0}; // the cost of each number form 0 to 35

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int test_case;
	cin >> test_case;
	for(int index = 1; index <= test_case; index++)
	{
		cout << "Case " << index << ":\n";
		
		for(int i = 0; i < 36; i++){
			cin >> cost[i];
		}
		
		int n; // the number of test numbers
		cin >> n;
		while(n--)
		{
			int number;
			cin >> number;
			
			vector<int> minList; // store the base that has the same minimal cost
			int min = INT_MAX; // the minimal cost
			
			for(int base = 2; base <= 36; base++){
				int numberCopy = number;
				int count = 0;	// The total cost of current base
				while(numberCopy > 0)
				{
					count += cost[numberCopy % base];
					numberCopy /= base;
				}
				
				
				if(count < min){
					min = count;
					minList.clear();
					minList.push_back(base);
				}
				else if(count == min){
					minList.push_back(base);
				}
			}
			
			
			// output
			cout << "Cheapest base(s) for number " << number << ":";
			for(int num : minList){
				cout << " " << num;
			}
			cout << '\n';
		}
		if(index < test_case)	cout << '\n';
	}
	return 0;
}
