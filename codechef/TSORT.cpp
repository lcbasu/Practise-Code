#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	vector<int> in;
	while(t--)
	{
		int tmp;
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	sort(in.begin(),in.end());
	for (int i = 0; i < in.size(); ++i)
	{
		printf("%d\n",in[i]);
	}
	return 0;	
}