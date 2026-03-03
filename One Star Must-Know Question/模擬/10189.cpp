#include <iostream>
using namespace std;

char mine[105][105]; // map, mine -> '*', else -> 'number'

// +1 to the surrounding of mine on the map
void addMineOnMap(int& x, int& y, int& row, int& col){
	for(int i = x-1; i <= x+1; i++){
		if(i < 0 || i >= row) continue;
		
		for(int j = y-1; j <= y+1; j++){
			if(j < 0 || j >= col) continue;
			if(mine[i][j] != '*') mine[i][j]++;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int row, col;
	int index = 1; // output index
	bool isFirst = true; // Flag: is first round of while loop or not
	
	while(cin >> row >> col && (row != 0 && col != 0))
	{
		if(isFirst) isFirst = false; // output format
		else {
			cout << '\n';
			index++;
		}
		
		// initialize map
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				mine[i][j] = '0';
			}
		}
		
		// input map
		char ch;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cin >> ch;
				if(ch == '*'){
					// if it is mine
					// then +1 to the surrounding cell on map
					mine[i][j] = '*';
					addMineOnMap(i, j, row, col);
				}
			}
		}
		
		// output
		cout << "Field #" << index << ":\n";
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cout << mine[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
