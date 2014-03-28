#include <iostream>

using namespace std;

struct Node
{
	int acad;
	int sports;
	int commSkill;
	int totalScore;
};


Node *rankList;

Node *firstStudent;


void swap(Node *a, Node *b)
{
	Node *tmp = a;
	*a = *b;
	*b = *tmp;

}

void sort(Node *rankListPtr, int n)
{
	if(n<1)
		return;
	for (int i = 0; i < n; ++i)
	{
		bool noSwapping = true;
		for(int j = 0; j < n-i-1; j++)
		{
			if(rankList[j].acad >= 30 && rankList[j].sports >= 30 && rankList[j].commSkill >= 30)
			{
				if(rankList[j].totalScore > rankList[j+1].totalScore)
				{
					noSwapping = false;
					swap(rankList[j], rankList[j+1]);
				}
				else if(rankList[j].totalScore == rankList[j+1].totalScore && rankList[j].acad > rankList[j+1].acad)
				{
					noSwapping = false;
					swap(rankList[j], rankList[j+1]);
				}
				else if(rankList[j].totalScore == rankList[j+1].totalScore && rankList[j].acad == rankList[j+1].acad && rankList[j].sports == rankList[j+1].sports)
				{
					noSwapping = false;
					swap(rankList[j], rankList[j+1]);
				}								
			}
		}
		if(noSwapping)
			break;
	}

}



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		rankList = new Node[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> rankList[i].acad;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> rankList[i].sports;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> rankList[i].commSkill;
			rankList[i].totalScore = rankList[i].acad + rankList[i].sports + rankList[i].commSkill;
		}
		firstStudent = new Node;
		firstStudent->acad = rankList[0].acad;
		firstStudent->sports = rankList[0].sports;
		firstStudent->commSkill = rankList[0].commSkill;
		sort(rankList, n);
		bool madeToDeanList = false;
		for (int i = 0; i < 3; ++i)
		{
			if(firstStudent->acad == rankList[i].acad && firstStudent->sports == rankList[i].sports && firstStudent->commSkill == rankList[i].commSkill)
			{
				madeToDeanList = true;
				break;
			}
		}
		if(madeToDeanList)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}