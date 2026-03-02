#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

int ans[505] = {0}; // The answer of G(n), n is integer

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	
	//	build ans list, G(n) has connection with G(n-1)
	//	G(n) = G(n-1) + gcd(i, n), where i = 1 ~ n-1
	ans[0] = 0;
	ans[1] = 0;
	ans[2] = 1;
	for(int index = 3; index < 505; index++){
		ans[index] = ans[index-1];
		for(int i = 1; i < index; i++){
			ans[index] += gcd(i, index);
		}
	}
	
	
	int n;
	while(cin >> n && n != 0)
	{
		cout << ans[n] << '\n';
	}
	return 0;
}
