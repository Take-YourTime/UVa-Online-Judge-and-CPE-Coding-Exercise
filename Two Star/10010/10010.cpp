#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char map[52][52];


// check if there is an answer string in the eight way
bool solve(const int& row, const int& col, const string& str, const int& x, const int& y)
{
	const int size = str.size();
	
	// special case
	if(size == 1) return true;
	
	int currentX, currentY;
	int index;
	
	
	// go right
	if(y + (size - 1) <= col){
		currentX = x;
		currentY = y + 1;
		index = 1;
		while(map[currentX][currentY] == str[index]){
			index++;
			currentY++;
			
			if(index == size) return true;
		}
	}
	
	// go left
	if(y - (size - 1) >= 0){
		currentX = x;
		currentY = y - 1;
		index = 1;
		while(map[currentX][currentY] == str[index]){
			index++;
			currentY--;
			
			if(index == size) return true;
		}
	}
	
	// go down
	if(x + (size - 1) <= row){
		currentX = x + 1;
		currentY = y;
		index = 1;
		while(map[currentX][currentY] == str[index]){
			index++;
			currentX++;
			
			if(index == size) return true;
		}
	}
	
	// go up
	if(x - (size - 1) >= 0){
		currentX = x - 1;
		currentY = y;
		index = 1;
		while(map[currentX][currentY] == str[index]){
			index++;
			currentX--;
			
			if(index == size) return true;
		}
	}
	
	// go right and down
	if(y + (size - 1) <= col && x + (size - 1) <= row){
		currentX = x + 1;
		currentY = y + 1;
		index = 1;
		while(map[currentX][currentY] == str[index]){
			index++;
			currentX++;
			currentY++;
			
			if(index == size) return true;
		}
	}
	
	// go right and up
	if(y + (size - 1) <= col && x - (size - 1) >= 0){
		currentX = x - 1;
		currentY = y + 1;
		index = 1;
		while(map[currentX][currentY] == str[index]){
			index++;
			currentX--;
			currentY++;
			
			if(index == size) return true;
		}
	}
	
	// go left and down
	if(y - (size - 1) >= 0 && x + (size - 1) <= row){
		currentX = x + 1;
		currentY = y - 1;
		index = 1;
		while(map[currentX][currentY] == str[index]){
			index++;
			currentX++;
			currentY--;
			
			if(index == size) return true;
		}
	}
	
	// go left and up
	if(y - (size - 1) >= 0 && x - (size - 1) >= 0){
		currentX = x - 1;
		currentY = y - 1;
		index = 1;
		while(map[currentX][currentY] == str[index]){
			index++;
			currentX--;
			currentY--;
			
			if(index == size) return true;
		}
	}
	
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int testCase;
	int row, col;
	int line; // the number of testing string
	string str;
	
	cin >> testCase;
	while(testCase--)
	{
		// input
		cin >> row >> col;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cin >> map[i][j];
				
				// make all the characters is lowercase
				if(isupper(map[i][j])) map[i][j] = tolower(map[i][j]);
			}
		}
		
		cin >> line;
		while(line--)
		{
			cin >> str;
			for(int i = 0; i < str.size(); i++){
				
				// make all the characters is lowercase
				if(isupper(str[i])) str[i] = tolower(str[i]);
			}
			
			
			int ansRow = 105; // answer position
			int ansCol = 105;
			
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
					// find the identical string
					if( map[i][j] == str[0] && solve(row, col, str, i, j) ){
						
						// check and update the upper most then leftest most position of the identical string
						if(i < ansRow){ // upper most
							ansRow = i;
							ansCol = j;
						}
						else if(i == ansRow && j < ansCol){ // upper most and leftest most
							ansRow = i;
							ansCol = j;
						}
					}
				}
			}
			
			cout << ansRow+1 << " " << ansCol+1 << '\n';
		}
		
		if(testCase) cout << '\n';
	}
	return 0;
}
