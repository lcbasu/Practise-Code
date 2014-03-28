#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	while(!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}