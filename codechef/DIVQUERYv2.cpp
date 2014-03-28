#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;


struct Query
{
	int L;
	int R;
	int K;
};

struct FQuery	//Fragmented Query
{
	int index;
	int K;
};

bool mySortComparator(FQuery *a, FQuery *b)
{
	return ((a->index < b->index) && (a->K < b->K));
}

int main()
{
	//taking index at 1 instead of zero so size+1 is used for array througout
	int N, Q;
	scanf("%d %d", &N, &Q);
	int *A = new int[N+1];
	A[0] = 0;
	for (int i = 1; i < N+1; ++i)
	{
		scanf("%d", &A[i]);
	}
	int t = Q;

	int maxK = 0;

	vector<int> listOfK;

	//list of the initial Query
	vector<Query *> queryList;
	while(t--)
	{
		Query *node = new Query();
		scanf("%d %d %d", &node->L, &node->R, &node->K);
		queryList.push_back(node);
		if(node->K > maxK)
			maxK = node->K;
		listOfK.push_back(node->K);
	}


	vector<FQuery *> fQueryList;
	//storing query(l,k) and query(r,k)
	for (int i = 0; i < Q; ++i)
	{
		Query *tmp = queryList[i];
		FQuery *newFNode;

		newFNode = new FQuery();
		newFNode->index = tmp->L;
		newFNode->K = tmp->K;
		fQueryList.push_back(newFNode);

		newFNode = new FQuery();
		newFNode->index = tmp->R;
		newFNode->K = tmp->K;
		fQueryList.push_back(newFNode);		
	}
	sort(fQueryList.begin(), fQueryList.end(), mySortComparator);

	int *count = new int[maxK+1];
	for (int i = 0; i < maxK+1; ++i)
	{
		count[i] = 0;
	}

	map<FQuery *, int > result;

	for (int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= A[i]; j++)
		{
			if(A[i]%j == 0)
				count[j]++;
		}
		for(int m = 0; m < listOfK.size(); m++)
		{
			FQuery *tmp = new FQuery();
			tmp->index = i;
			tmp->K = listOfK[m];
			result[tmp] = count[listOfK[m]];
		}
	}

	for (int i = 0; i < Q; ++i)
	{
		int L = queryList[i]->L;
		int R = queryList[i]->R;
		int K = queryList[i]->K;
	}

	return 0;
}