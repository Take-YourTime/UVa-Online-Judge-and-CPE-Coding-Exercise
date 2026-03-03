#include <iostream>
using namespace std;

char mine[105][105];

void addMineOnMap(int& x, int& y, int& col, int& row){
	for(int i = x-1; i <= x+1; i++){
		if(i < 0 || i >= col) continue;
		
		for(int j = y-1; j <= y+1; j++){
			if(j < 0 || j >= row) continue;
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
	int index = 1;
	bool isFirst = true;
	while(cin >> row >> col && (row != 0 && col != 0))
	{
		if(isFirst) isFirst = false;
		else {
			cout << '\n';
			index++;
		}
		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				mine[i][j] = '0';
			}
		}
		
		char ch;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cin >> ch;
				if(ch == '*'){
					mine[i][j] = '*';
					addMineOnMap(i, j, col, row);
				}
			}
		}
		
		
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
