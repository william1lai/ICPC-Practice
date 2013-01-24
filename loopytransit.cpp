#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::vector;
using std::string;


int stations;
vector < vector<bool> > links;
vector <string> usedPaths;
vector <bool> travelled;
int paths;

void readInput()
{
	cin >> stations;
	links.resize(stations);
	//usedLinks.resize(stations);

	for (int i = 0; i < stations; i = i + 1)
	{
		links[i].resize(stations);
		//usedLinks[i].resize(stations);
	}
	travelled.resize(stations);

	int connections;
	cin >> connections;

	for (int i = 0; i < connections; i = i + 1)
	{
		int first; //first station
		int second; //second station

		cin >> first >> second;

		links[first][second] = true;
	}
	return;
}

vector<int> findLinks(int station)
{
	vector<int> poslinks;
	cout << "Links: ";
	for (int i = 0; i < links.size(); i = i + 1)
	{
		if (links[station][i] == true)
		{
			poslinks.push_back(i);
			cout << i << " ";
		}
	}
	cout << endl;
	return poslinks;
}

bool checkLoop(string cpath)
{
	sort(cpath.begin(), cpath.end());

	for (int i = 1; i < cpath.size(); i = i + 1)
	{
		if (cpath.at(i) == cpath.at(i - 1))
		{
			return true;
		}
	}
	return false;
}

int findPaths(string cpath)
{
	if (checkLoop(cpath))
	{
		cout << "LOOP!" << endl;
		return 1;
	}
	else
	{
		int count = 0;
		string last = cpath.substr(cpath.size() - 1);
		//cout << last << endl;
		int station = stoi(cpath.substr(cpath.size() - 1));
		cout << "From Station: " << station << endl;

		vector<int> poslinks = findLinks(station);

		stringstream ss;
		cout << "Current Path: " << cpath << endl;

		int sum = 0;
		while (poslinks.size() > 0)
		{
			ss << poslinks.at(poslinks.at(poslinks.size() - 1));
			poslinks.pop_back();
			sum = sum + findPaths(ss.str());
		}
	}
}

int main()
{
	readInput();
	paths = findPaths("0"); //start from first, should get to all stations

	for (int i = 0; i < usedPaths.size(); i = i + 1)
	{
		cout << usedPaths[i] << endl;
	}

	cout << endl;

	cout << "Paths: " << paths << endl;

	return 0;
}