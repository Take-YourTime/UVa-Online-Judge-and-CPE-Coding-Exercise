#include <iostream>
using namespace std;

char map[105][105];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int test_case;
	int row, col, pos;
	cin >> test_case;
	
	while(test_case--)
	{
		// input
		cin >> row >> col >> pos;
		cout << row << " " << col << " " << pos << '\n';

		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++){
				cin >> map[i][j];
			}
		}
		
		
		int centerX, centerY;	// cneter of square
		while(pos--)
		{
			cin >> centerX >> centerY;
			
			char key = map[centerX][centerY];	// the element of center of square
			int size = 1;	// square size = size * 2 - 1;
			int x, y;		// a position in square
			
			
			
			while(	centerX - size >= 0 && centerX + size < row && 
					centerY - size >= 0 && centerY + size < col	) // check the position is in the square
			{	
				int i;
				bool isIdentical = true; // flag: element is identical to "key"
				
				// Check the surround of the square
				// Fist check size 3*3, second 5*5, ...
				
				// Initial position - top left of the square
				x = centerX - size;
				y = centerY - size;
				
				// go right
				for(i = 0; i < size * 2; i++){
					if(map[x][y] != key){
						isIdentical = false;
						break;
					}
					y++;
				}
				if(!isIdentical)	break;
				
				// go down
				for(i = 0; i < size * 2; i++){
					if(map[x][y] != key){
						isIdentical = false;
						break;
					}
					x++;
				}
				if(!isIdentical)	break;
				
				// go left
				for(i = 0; i < size * 2; i++){
					if(map[x][y] != key){
						isIdentical = false;
						break;
					}
					y--;
				}
				if(!isIdentical)	break;
				
				// go up
				for(i = 0; i < size * 2; i++){
					if(map[x][y] != key){
						isIdentical = false;
						break;
					}
					x--;
				}
				if(!isIdentical)	break;
				
				size++;
			}
			
			cout << size*2 - 1 << '\n';
		}
	}
	return 0;
}
