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
	
	string str;
	vector<int> coef; // coefficient sequence
	vector<int> inputSequence; // x sequence
	stringstream ss;
	
	while(getline(cin, str))
	{
		int n; // input buffer
		
		// coeficient input
		ss.clear();
		ss.str(str);
		coef.clear();
		while(ss >> n){
			coef.push_back(n);
		}
		
		// x input
		getline(cin, str);
		ss.clear();
		ss.str(str);
		inputSequence.clear();
		
		
		int sum = 0;	// result of equation due to input x
		int power = 1;	// x's power
		
		// calculate and ouput the result of first x (output format request!)
		ss >> n;
		for(int i = coef.size()-1; i >= 0; i--) {
			/* Watch out! */
			// We can't use pow() here, since pow() is calculate in double type!
			sum += coef[i] * power;
			power *= n;
		}
		cout << sum;
		
		// calculate and ouput the results of rest x
		while(ss >> n){
			sum = 0;
			power = 1;
			for(int i = coef.size()-1; i >= 0; i--) {
				sum += coef[i] * power;
				power *= n;
			}
			cout << " " << sum;
		}
		cout << '\n';
	}
	return 0;
}
