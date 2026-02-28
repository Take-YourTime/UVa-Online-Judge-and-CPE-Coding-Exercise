#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int size; // input sequence size
	int arr[3005];
	
	while(cin >> size)
	{	
		bool diff[3005] = {false}; // the occurrence of difference between two number in the sequence
	
		cin >> arr[0];
		if(size == 1){
			//	special case: size = 1 -> must be jolly
			cout << "Jolly\n";
			continue;
		}
		else if(size < 1){
			//	special case: size < 1 -> must be non-jolly
			cout << "Not jolly\n";
			continue;
		}
		
		
		
		bool isJolly = true; // flag: is jolly or not
		
		// input the sequence and record difference, O(n)
		for(int i = 1; i < size; i++){
			cin >> arr[i];
			diff[ abs(arr[i] - arr[i-1]) ] = true;
		}
		
		// check if the differences form 1 to size-1 is occurred, O(n)
		for(int i = 1; i < size; i++){
			if(diff[i] == false){
				isJolly = false;
				break;
			}
		}
		
		// output
		if(isJolly) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
	return 0;
}
