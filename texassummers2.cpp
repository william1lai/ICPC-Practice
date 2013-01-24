#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
	int x;
	int y;
};

struct IntPair
{
	int first;
	int second;
};

queue<IntPair> q; //for queueing searches
vector<double> cumuCost; //where index 0 = dorm
vector<bool> processed;
vector<Point> locations; //where index 0 = dorm and index size - 1 = class;
vector<int> parent; //where parent is the previous index
//vector<vector<int> > adjCosts; //index [i][j] = cost from locations[i] to location[j]

double cost(Point first, Point second)
{
	return /*sqrt*/((first.x - second.x)*(first.x - second.x) + (first.y - second.y)*(first.y - second.y));
}

void getInput()
{
	int shadySpots;
	cin >> shadySpots;

	for (int i = 0; i < shadySpots + 2; i = i + 1)
	{
		int xa;
		int ya;
		cin >> xa >> ya;
		Point p;
		p.x = xa;
		p.y = ya;

		locations.push_back(p);
		vector<int> v;
		cumuCost.push_back(DBL_MAX);
		processed.push_back(false);
		parent.push_back(-1);
	}
	cumuCost[cumuCost.size() - 2] = 0; //otherwise processing won't work
}

void process()
{
	while (! q.empty())
	{
		int f = q.front().first;
		int s = q.front().second;
		q.pop();
		double tempCost = cumuCost[f] + cost(locations[f], locations[s]);

		if ((tempCost < cumuCost[s]) || (cumuCost[s] == DBL_MAX))
		{
			cumuCost[s] = tempCost;
			parent[s] = f;
			
			/*
			if (s == locations.size() - 1)
			{
				cout << "Parent: " << f << endl;
			}
			*/

			for (int i = 0; i < locations.size(); i = i + 1)
			{
				IntPair temp;
				temp.first = s;
				temp.second = i;
				q.push(temp);
				if ((s != locations.size() - 1) || (s != locations.size() - 2))
				{
					process();
				}
			}
		}
	}
}

void bfs(int start)
{
	for (int i = 0; i < locations.size(); i = i + 1)
	{
		if (i != start)
		{
			IntPair temp;
			temp.first = start;
			temp.second = i;
			q.push(temp);
			process();
		}
	}
	//process();
	/*
	if (start < locations.size() - 2) //if we haven't yet processed every location
	{
		bfs(start + 1);
	}
	*/
}

void printPath(int n) //prints path from dorm to class
{
	if ((n == (locations.size() - 1)) || (n == locations.size() - 2))
	{ //do nothing if back at dorm or at class
	}
	else
	{
		printPath(parent[n]);
		cout << n << endl;
	}

}

int main()
{
	getInput();
	bfs(locations.size() - 2);

	if (parent[locations.size() - 1] == (locations.size() - 2))
	{
		cout << "-" << endl;
		return 0;
	}
	else
	{
		printPath(parent[locations.size() - 1]);
	}
}