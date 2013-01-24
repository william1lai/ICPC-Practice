#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int stackNum;
vector<vector <int> > stacks;
vector<int> order;
int opCount = 0;

void getInput()
{
	cin >> stackNum;

	for (int i = 0; i < stackNum; i = i + 1)
	{
		int stackCount;
		vector<int> vtemp;
		stacks.push_back(vtemp);
		cin >> stackCount;
		for (int j = 0; j < stackCount; j = j + 1)
		{

			int diameter;
			cin >> diameter;
			stacks[i].push_back(diameter);
			order.push_back(diameter);
		}
	}
}

void findOrder()
{
	sort(order.begin(), order.end());
}

void splitnjoin()
{
	for (int i = 0; i < stackNum; i = i + 1)
	{
		for (int j = 0; j < stacks[i].size() - 1; j = j + 1)
		{
			vector<int>::iterator indexf = find(order.begin(), order.end(), stacks[i][j]);
			if (*(indexf + 1) != stacks[i][j + 1]) //if below is shorter than above
			{
				opCount = opCount + 1;
			}
		}
	}
	stackNum = opCount + stackNum;
	int joins = stackNum - 1;
	opCount = opCount + joins;
	cout << opCount << endl;
}

int main()
{
	getInput();
	findOrder();
	splitnjoin();
}