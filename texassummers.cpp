#include <iostream>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

struct Location
{
public:
	int x;
	int y;
};

vector<Location> spots;
Location dorm;
Location cl;
int minPath = 0;
double min = DBL_MAX;

double distance(Location first, Location second)
{
	return sqrt(static_cast<double>((second.x - first.x)*(second.x - first.x) + (second.y - first.y)*(second.y - first.y)));
}

void getInput()
{
	int numOfSpots;
	cin >> numOfSpots;

	int nx;
	int ny;
	for (int i = 0; i < numOfSpots; i = i + 1)
	{
		cin >> nx;
		cin >> ny;
		Location s;
		s.x = nx;
		s.y = ny;
		spots.push_back(s);
	}

	cin >> nx >> ny;
	dorm.x = nx;
	dorm.y = ny;

	cin >> nx >> ny;
	cl.x = nx;
	cl.y = ny;
}

void findPath(Location current, double sweat, int path) //returns path
{
	cout << "Current: " << current.x << " " << current.y << endl;
	cout << "Sweat: " << sweat << endl;
	cout << "Path: " << path << endl;
	cout << endl;

	double dist = distance(current, cl);
	double totLength = sweat + dist*dist;

	if (totLength < min)
	{
		min = totLength;
		minPath = path;
		cout << "Min Sweat: " << totLength << endl;
		cout << "Min Path: " << minPath << endl << endl;
	}

	stringstream ss;
	ss << path;
	string p = ss.str();

	for (int i = 0; i < spots.size(); i = i + 1)
	{
		ss << (int)(0) + i;
		string temp;
		ss >> temp;

		if (current.x == spots[i].x && current.y == spots[i].y)
		{} //do nothing if same location
		else if(p.find(temp) != -1)
		{
			cout << "FOUND" << endl;
			//do nothing, because the location has been visited previously
		}
		else
		{
			double toCl = distance(current, cl);
			double toCl2 = distance(spots[i], cl);

			//if (toCl2 < toCl)
			//{
			if (path == -1)
			{
				path = 0;
			}
			findPath(spots[i], sweat + distance(current, spots[i])*distance(current, spots[i]), path * 10 + i);
			//}
		}
	}
}

void printRevNum(int n)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		printRevNum(n / 10);
		cout << n % 10 << endl;
	}
}

int main()
{
	getInput();
	findPath(dorm, 0, -1);

	cout << "ANS: " << endl;

	if (minPath == -1)
	{
		cout << "-" << endl;
	}
	else
	{
		printRevNum(minPath);
	}

	return 0;
}