#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int x;
	string str;
	while(cin >> x)
	{
		cin.ignore();
		getline(cin, str);
		
		stringstream ss(str);
		vector<int> coef; // coefficient sequence
		int n; // input buffer
		
		while(ss >> n){
			coef.push_back(n);
		}
		
		// The equation is a constant
		if(coef.size() == 1){
			cout << 0 << '\n';
			continue;
		}
		
		int sum = 0;
		int power = 1;
		for(int i = coef.size()-2; i >= 0; i--)
		{
			/* Watch out! */
			// We can't use pow() here, since pow() is calculate in double type!
			sum += coef[i] * (coef.size()-i-1) * power;
			power *= x;
		}
		
		cout << sum << '\n';
	}
	return 0;
}
