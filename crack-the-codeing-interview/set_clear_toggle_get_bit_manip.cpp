#include <iostream>

using namespace std;

int main()
{
	//	setting the k-th bit, position for that is (k-1) here we set the 3rd bit so position is 2
	int set = 18;
	set = set | (1<<2);
	cout << "Set : " << set << endl;

	//	clearing the k-th bit, position for that is (k-1) here we clear the 5th bit so position is 4
	int clear = 18;
	clear = clear & ~(1<<4);
	cout << "Clear : " << clear << endl;

	//	toggle the k-th bit, position for that is (k-1) here we toggle the 4th bit so position is 3
	int toggle = 18;
	toggle = toggle ^ (1<<3);
	cout << "Toggle : " << toggle << endl;

	//	to get the k-th bit, position for that is (k-1) here we want to get the 2nd bit so position is 1
	int get = 18;
	get = get & (1<<1);
	cout << "Get : " << get << endl;

	return 0;
}