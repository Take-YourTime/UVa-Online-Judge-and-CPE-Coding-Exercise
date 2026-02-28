#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getWinRate(const int& player, const double& chance, double probability)
{
	return probability * chance * ( 1.0 / (1.0 - pow(1.0-chance, player)) ); // Geometric Sequence
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		int player;
		double chance;
		int key; // key player
		
		cin >> player >> chance >> key;
		
		// special case
		if(chance == 0.0){
			cout << "0.0000\n";
			continue;
		}
		
		double probability = pow((1.0-chance), key-1); // the chance to get the first dice (no throw)
		
		double result = getWinRate(player, chance, probability);
		
		cout << fixed << setprecision(4) << result << '\n';
	}
	return 0;
}
