#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> dictionary;


//	build up dictionary: character -> number
void buildDictionary(void)
{
	for(int i = 0; i <= 9; i++){
		dictionary[char('0' + i)] = i;
	}
	for(int i = 0; i < 26; i++){
		dictionary[char('A' + i)] = 10 + i;
	}
	for(int i = 0; i < 26; i++){
		dictionary[char('a' + i)] = 36 + i;
	}
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	buildDictionary();
	
	string n;
	while(cin >> n)
	{
		//	ignore sign symbol
		if(n[0] == '+' || n[0] == '-'){
			n.erase(n.begin());
		}
		
		//	number is 0 -> output base 2 immediately, since 0 will make array index become -1 in the below code
		if(n == "0"){
			cout << 2 << '\n';
			continue;
		}
		
		
		//	find the max digit of the number
		int max = 0;
		for(char ch : n){
			if(dictionary[ch] > max)	max = dictionary[ch];
		}
		
		
		//	find the proper base
		int base;
		int sum;
		for(base = max+1; base <= 62; base++){
			sum = 0;
			for(int i = n.size()-1; i >= 0; i--){
				sum *= base;
				sum += dictionary[ n[n.size()-1-i] ];
				sum %= (base-1);	// mod "sum" each time, or the number will overload
			}
			
			if(sum % (base-1) == 0)	break;
		}
		
		if(base == 63){
			cout << "such number is impossible!\n";
		}
		else{
			cout << base << '\n';
		}
	}
	return 0;
}


//	如使用以下定理，能使執行速度更快一些：

//	一個N進位制的數，表示成【abc】 = a * N^2 + b * N + c
//		= a*N*(N-1+1) + b*(N-1+1) + c
//		= a*N*(N-1) + a*N + b*(N-1) + b + c
//		= a*N*(N-1) + a*(N-1) + a + b*(N-1) + b + c
//		= (a * N + a + b) * (N-1) + (a + b + c)

//	→ 如果一個N進位制的數【abc】是 (N-1) 的倍數，則 (a + b + c) 也是(N-1) 的倍數

//	來源：https://yuihuang.com/uva-10093/