#include <iostream>

using namespace std;

int atoi(char *pStr)
{
	if(pStr == NULL)
		return 0;
	bool isSigned = false;
	if(*pStr == '-' || *pStr == '+')
	{
		if(*pStr == '-')
			isSigned = true;
		pStr++;
	}
	char *currPtr = pStr;
	while((currPtr != NULL) && (*currPtr >= '0' && *currPtr <= '9'))
		currPtr++;

	currPtr--;

	//in case no numeric value just after the sign or no sign
	if((currPtr == pStr) || !(*currPtr >= '0' && *currPtr <= '9'))	//when only sign is there or only one non-numeric symbol after sign
		return 111; //returning 'o'
	int sum = 0;
	int ten = 1;
	for(; currPtr >= pStr; currPtr--)
	{
		int digit = *currPtr - '0';
		sum += digit*ten;
		ten *= 10;
	}
	if(isSigned)
		sum *= -1;
	return sum;
}

int main()
{
	char *str = "12A";
	cout << atoi(str) << endl;
	return 0;
}
