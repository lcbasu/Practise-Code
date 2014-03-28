#include <iostream>
#define NO_OF_CHAR 256
using namespace std;

int maxCount = 0;
char maxChar;

void *getCountArray(char *c){
	int *tmp=new int[NO_OF_CHAR];
	int i=0;
	while(*(c+i))
	{
		tmp[*(c+i)]++;
		if(tmp[*(c+i)] > maxCount)
		{
			maxCount = tmp[*(c+i)];
			maxChar = *(c+i);
		}
		i++;
	}
}

int main(){
	char c[]="teeeeest string";
	getCountArray(c);
	cout << maxCount << endl;
	cout << maxChar << endl;
	return 0;
}