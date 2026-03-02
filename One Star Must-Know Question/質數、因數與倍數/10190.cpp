#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	long long int number, key;
	vector<int> list;
	while(cin >> number >> key)
	{
		if(number <= 1 || key <= 1 || number < key)
		{
			cout << "Boring!" << '\n';
			continue;
		}
		
		list.clear();
		bool isBoring = false;
		while(number > 1)
		{
			if(number % key != 0){
				isBoring = true;
				break;
			}
			list.push_back(number);
			number /= key;
		}
		
		if(isBoring) cout << "Boring!" << '\n';
		else{
			for(int n : list) cout << n << " ";
			cout << "1\n";
		}
	}
	return 0;
}
