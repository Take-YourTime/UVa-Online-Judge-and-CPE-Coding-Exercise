#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi = acos(-1);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	double r;	// radius
	double degree;
	string type;
	
	while(cin >> r >> degree >> type)
	{
		//	angle adjust
		if(type == "min") degree /= 60.0;
		while(degree >= 360.0) degree -= 360.0;
		if(degree >= 180.0)	degree = 360.0 - degree;
		
		r += 6440.0;	// plus the radius of Earth
		
		double angle = pi * 2 * (degree / 360.0);
		double line = sqrt(r * r * 2 - r * r * 2 * cos(angle)); // r * r * 2 - r * r * 2 * cos(angle) by Cosine Rule
		double arc = r * 2 * pi * (degree / 360.0);
	
		cout << fixed << setprecision(6) << arc << " " << line << '\n';
	}
	return 0;
}
