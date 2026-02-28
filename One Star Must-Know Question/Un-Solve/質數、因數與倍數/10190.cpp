#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long int n, m;
	vector<long long int> list;
	
	while(!cin.eof() && cin >> n >> m)
	{
		if(n <= 1 || m <= 1 || n < m || n >= 2000000000 || m >= 2000000000)
		{
			cout << "Boring!" << endl;
			continue;
		}
		
		list.clear();
		list.push_back(n);
		
		//	whether is boring
		bool isboring = false;
		
		//	calculate
		while( n > 1)
		{
			if(n % m == 0)
			{
				n /= m;
				list.push_back(n);
			}
			else
			{
				isboring = true;
				break;
			}	
		}
		
		if(isboring)
			cout << "Boring!" << endl;
		else
		{
			for(int i = 0; i < list.size() - 1; i++)
				cout << list[i] << " ";
			cout << list[ list.size() - 1 ] << endl;
		}
	}
	return 0;
}
