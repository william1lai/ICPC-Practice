#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph
{
	vector <vector<int> > links;
};
struct DPair
{
	vector<int> v;
	int s;
};

Graph g;
queue<DPair> q; //queue of nodes to process
int loops = 0;


void initializeGraph(int n)
{
	for (int i = 0; i < n; i = i + 1)
	{
		vector<int> temp;
		g.links.push_back(temp);
		for (int j = 0; j < n; j = j + 1)
		{
			g.links[i].push_back(0);
		}
	}
}

void createLink(int f, int s)
{
	g.links[f][s] = true;
}

void processInput()
{
	int connections; //number of links
	cin >> connections;

	int first;
	int second;

	for (int i = 0; i < connections; i = i + 1)
	{
		cin >> first >> second;
		createLink(first, second);
	}
}

void process(int start)
{
	DPair x = q.front();
	q.pop();
	int station = x.s;
	vector<int> visited = x.v;
	visited[x.s] = true;
	for (int i = 0; i < g.links.size(); i = i + 1)
	{
		if (g.links[station][i] == true)
		{
			if (i == start)
			{
				loops = loops + 1;
				cerr << station << " " << i << endl;
			}
			else if (visited[i] == true)
			{ //do nothing
			}
			else
			{
				DPair d;
				d.s = i;
				d.v = visited;
				q.push(d);
				process(start);
			}
		}
	}
}

void dfs(int start)
{
	vector<int> va;
	for (int i = 0; i < g.links.size(); i = i + 1)
	{
		va.push_back(false);
	}
	va[start] = true;
	DPair first;
	first.s = start;
	first.v = va;
	q.push(first);
	process(start);
}

void remove(int n) //removes station
{
	for (int i = 0; i < g.links.size(); i = i + 1)
	{
		if (g.links[i][n] == true) //if there is link between other station and this one
		{
			g.links[i][n] = false;
		}
	}
}

int main()
{
	int n;
	cin >> n; //get number of nodes
	initializeGraph(n);

	processInput();

	for (int i = 0; i < g.links.size(); i = i + 1)
	{
		dfs(i);
		remove(i);
	}
	
	cout << loops;
	cerr << endl;
}