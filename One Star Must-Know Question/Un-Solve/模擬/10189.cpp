#include <iostream>
using namespace std;

typedef char* CHAR_PTR;

int main()
{
	int m, n;
	CHAR_PTR* map;
	
	int test_case = 0;
	
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
			break;
		else if(test_case > 0)
			cout << endl;
		else if(m == 0 || n == 0)
		{
			cout << "Wrong map size!\n";
			exit(EXIT_FAILURE);
		}
		
		//	create the map, and reset all element to '0'
		map = new CHAR_PTR[m];
		for(int i = 0; i < m; i++)
		{
			map[i] = new char[n];
			for(int j = 0; j < n; j++)
				map[i][j] = '0';
		}
			
		char ch;
		int side = 2;
		int move[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
		
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> ch;
				
				if(ch == '*')
				{
					map[i][j] = '*';
					
					int x = i - 1, y = j - 1;
					
					for(int way = 0; way < 4; way++)
					{
						for(int moving_times = 0; moving_times < side; moving_times++)
						{ 
							x += move[way][0];
							y += move[way][1];
							
                            if( (x >= 0 && x < m && y >= 0 && y < n) && (map[x][y] != '*') )
                            	map[x][y] += 1;
						}
					}
				}
			}
		}
		
		//	output and return memory
		test_case++;
		cout << "Field #" << test_case << ":\n";
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
				cout << map[i][j];
			cout << '\n';
			delete[] map[i];
		}
		delete[] map;
	}
	return 0;
}