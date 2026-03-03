#include <iostream>
#include <string>
#include <map>
using namespace std;

bool deadMap[52][52] = {false};
// false -> safe
// true -> a robot dead before


const char way[4] = {'E', 'S', 'W', 'N'};
int width, height; // map size
bool isDead;
map<char, int> wayToIndex; // map "mode" character to index of array "way"


void switchMode(char& mode, const char& command)
{
	int index = wayToIndex[mode];
	
	if(command == 'L') index = (index-1+4) % 4;
	else index = (index+1) % 4;
	
	mode = way[index];
}


void goForward(int& x, int& y, const char& mode){
	switch(mode){
		case 'E':{
			if(x+1 > width){
				if(!deadMap[x][y]) {
					isDead = true;
					deadMap[x][y] = true;
				}
				return;
			}
			x++;
			break;
		}
		case 'S':{
			if(y-1 < 0){
				if(!deadMap[x][y]) {
					isDead = true;
					deadMap[x][y] = true;
				}
				return;
			}
			y--;
			break;
		}
		case 'W':{
			if(x-1 < 0){
				if(!deadMap[x][y]) {
					isDead = true;
					deadMap[x][y] = true;
				}
				return;
			}
			x--;
			break;
		}
		case 'N':{
			if(y+1 > height){
				if(!deadMap[x][y]) {
					isDead = true;
					deadMap[x][y] = true;
				}
				return;
			}
			y++;
			break;
		}
		default:{
			break;
		}
	}
}


int main()
{
	// initialize mapping
	wayToIndex['E'] = 0;
	wayToIndex['S'] = 1;
	wayToIndex['W'] = 2;
	wayToIndex['N'] = 3;
	
	int x, y; // position
	char mode;
	string command;
	
	cin >> width >> height;
	
	while(cin >> x >> y >> mode)
	{
		isDead = false;
		cin >> command;
		for(char ch : command){
			switch(ch){
				case 'F':{
					goForward(x, y, mode);
					break;
				}
				case 'R':{
					switchMode(mode, ch);
					break;
				}
				case 'L':{
					switchMode(mode, ch);
					break;
				}
				default:{
					break;
				}
			}
			
			if(isDead) break;
		}
		
		cout << x << " " << y << " " << mode;
		if(isDead) {
			cout << " " << "LOST";
		}
		cout << '\n';
	}
	return 0;
}
