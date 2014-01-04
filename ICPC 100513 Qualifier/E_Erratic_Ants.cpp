#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Point
{
	int r;
	int c;
	int steps;
};

struct Dir
{
	bool left;
	bool right;
	bool up;
	bool down;
};

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		int steps;
		cin >> steps;
		cin.ignore(1000, '\n');

		Dir world[121][121];
		for (int z = 0; z < 121; z++)
		for (int zz = 0; zz < 121; zz++)
		{
			world[z][zz].up = false;
			world[z][zz].down = false;
			world[z][zz].right = false;
			world[z][zz].left = false;
		}


		int r = 60;
		int c = 60;

		for (int j = 0; j < steps; j++)
		{
			string step;
			getline(cin, step);

			if (step == "N")
			{
				world[r][c].up = true;
				r++;
				world[r][c].down = true;
			}
			else if (step == "S")
			{
				world[r][c].down = true;
				r--;
				world[r][c].up = true;
			}
			else if (step == "W")
			{
				world[r][c].left = true;
				c--;
				world[r][c].right = true;
			}
			else if (step == "E")
			{
				world[r][c].right = true;
				c++;
				world[r][c].left = true;
			}
		}

		queue<Point> mq;
		Point orig;
		orig.r = 60;
		orig.c = 60;
		orig.steps = 0;
		mq.push(orig);

		Point p;
		while (!mq.empty())
		{
			p = mq.front();
			mq.pop();

			int ts = p.steps + 1;

			world[p.r + 1][p.c].down = false;
			world[p.r - 1][p.c].up = false;
			world[p.r][p.c - 1].right = false;
			world[p.r][p.c + 1].left = false;
			
			if (p.c == c && p.r == r)
			{
				break;
			}

			if (world[p.r][p.c].down)
			{
				Point temp;
				temp.r = p.r - 1;
				temp.c = p.c;
				temp.steps = ts;
				mq.push(temp);
			}
			if (world[p.r][p.c].up)
			{
				Point temp;
				temp.r = p.r + 1;
				temp.c = p.c;
				temp.steps = ts;
				mq.push(temp);
			}
			if (world[p.r][p.c].right)
			{
				Point temp;
				temp.r = p.r;
				temp.c = p.c + 1;
				temp.steps = ts;
				mq.push(temp);
			}
			if (world[p.r][p.c].left)
			{
				Point temp;
				temp.r = p.r;
				temp.c = p.c - 1;
				temp.steps = ts;
				mq.push(temp);
			}
		}
		cout << p.steps << endl;
	}
	return 0;
}