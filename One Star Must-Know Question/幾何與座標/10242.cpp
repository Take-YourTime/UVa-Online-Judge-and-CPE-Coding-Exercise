#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	double a, b, c, d;
	double e, f, g, h;
	
	double x, y;
	
	while(cin >> a >> b >> c >> d >> e >> f >> g >> h)
	{
		if(a == e && b == f){
			x = (c - a) + g;
			y = (d - b) + h;
		}
		else if(a == g && b == h){
			x = (c - a) + e;
			y = (d - b) + f;
		}
		else if(c == e && d == f){
			x = (a - c) + g;
			y = (b - d) + h;
		}
		else { // c == g && d == h
			x = (a - c) + e;
			y = (b - d) + f;
		}
		
		cout << fixed << setprecision(3) << x << " " << y << '\n';
	}
	return 0;
}

