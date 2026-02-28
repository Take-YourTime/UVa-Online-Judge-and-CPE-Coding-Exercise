#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef bool* BOOL_PTR;

//	The map pointer
BOOL_PTR* map;

/*--------------------------------------------------*/

class Robot{
	public:
		Robot() = default;
		Robot(int, int, char, string);
		
		void run(int, int);
		
	private:
		int x;
		int y;
		char position;
		string command;
};

Robot::Robot(int loc_x, int loc_y, char pos, string str)
{
	this->x = loc_x;
	this->y = loc_y;
	this->position = pos;
	this->command = str;
}

void Robot::run(int width, int height)
{
	for(int i = 0; i < this->command.size(); i++)
	{
		switch(this->command[i])
		{
			case 'L':
				switch(this->position)
				{
					case 'N':
						this->position = 'W';
						break;
					case 'E':
						this->position = 'N';
						break;
					case 'S':
						this->position = 'E';
						break;
					case 'W':
						this->position = 'S';
						break;
					default:
						cout << "Wrong position!\n";
						exit(EXIT_FAILURE);		
				}
				break;
			case 'R':
				switch(this->position)
				{
					case 'N':
						this->position = 'E';
						break;
					case 'E':
						this->position = 'S';
						break;
					case 'S':
						this->position = 'W';
						break;
					case 'W':
						this->position = 'N';
						break;
					default:
						cout << "Wrong position!\n";
						exit(EXIT_FAILURE);	
				}
				break;
			//	go forward
			case 'F':{
				//	new location
				int moved_x = this->x;
				int moved_y = this->y;
				
				//	robot move
				switch(this->position)
				{
					case 'N':
						moved_y += 1;
						break;
					case 'E':
						moved_x += 1;
						break;
					case 'S':
						moved_y -= 1;
						break;
					case 'W':
						moved_x -= 1;
						break;
					default:
						cout << "Wrong position!\n";
						exit(EXIT_FAILURE);		
				}
				
				//	out of map
				if(moved_x >= width || moved_x < 0 || moved_y >= height || moved_y < 0)
				{
					//	There was a robot dead on the old location, and the new location is out of map.
					//	In this case, just do nothing!
					if(map[this->x][this->y] == true)
						break;
					else
					{
						//	robot die
						map[this->x][this->y] = true;
											
						cout << this->x << " " << this->y  << " " << this->position << " LOST\n";
						return;
					}
				}
				else
				{
					//	move
					this->x = moved_x;
					this->y = moved_y;
				}
				break;
			}
			default:
				cout << "Wrong command case!\n";
				exit(EXIT_FAILURE);
		}
	}
	
	cout << this->x << " " << this->y << " " << this->position << '\n';
}

int main()
{
	//	map size
	int width, height;
	cin >> width >> height;
	
	width += 1;
	height += 1;
	
	//	create the map
	//		flase: map初始值
	//		true: 表示曾有robot在這位置出界
	map = new BOOL_PTR[width];
	
	for(int i = 0; i < width; i++)
	{
		map[i] = new bool[height];
		for(int j = 0; j < height; j++)
		{
			map[i][j] = false;
		}
	}
		
	//	robot's location
	int new_robot_x, new_robot_y;
	
	//	robot's position
	char new_robot_pos;
	
	//	command
	string new_robot_com;
	
	while(cin >> new_robot_x >> new_robot_y >> new_robot_pos)
	{
		//	end program
		if(cin.eof())
		{
			//	delete map
			for(int i = 0; i < width; i++)
				delete [] map[i];
			delete [] map;
			
			return 0;
		}
		
		cin >> new_robot_com;
		Robot r(new_robot_x, new_robot_y, new_robot_pos, new_robot_com);
		
		r.run(width, height);
	}
}