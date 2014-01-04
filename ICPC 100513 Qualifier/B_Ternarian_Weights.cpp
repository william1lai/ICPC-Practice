#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		int n;
		cin >> n;

		vector<int> left;
		vector<int> right;

		int temp = 0;

		while (temp != n)
		{
			int diff = abs(temp - n);
			int pow3 = 1;

			while (abs(pow3 - diff) > (pow3 / 2))
			{
				pow3 = pow3 * 3;
			}

			if (temp < n)
			{
				temp = temp + pow3;
				right.push_back(pow3);
			}
			else
			{
				temp = temp - pow3;
				left.push_back(pow3);
			}
		}

		cout << "left pan:";
		if (!left.empty())
		{
			for (int j = 0; j < left.size(); j++)
				cout << " " << left[j];
		}
		cout << endl;

		cout << "right pan:";
		for (int j = 0; j < right.size(); j++)
			cout << " " << right[j];
		cout << endl;
	}
	return 0;
}