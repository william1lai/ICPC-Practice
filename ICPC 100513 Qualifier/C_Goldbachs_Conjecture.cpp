#include <iostream>
#include <vector>

using namespace std;

struct IntPair
{
	int first;
	int second;
};

int main()
{
	bool isPrime[32001];
	for (int i = 0; i < 32001; i++)
		isPrime[i] = true;

	for (int i = 2; i < 179; i++)
	{
		for (int j = i*i; j < 32001; j = j + i)
		{
			isPrime[j] = false;
		}
	}

	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		if (i != 0)
			cout << endl;

		vector<IntPair> pairs;
		int n;
		cin >> n;

		if (isPrime[n-2])
		{
			IntPair temp;
			temp.first = 2;
			temp.second = n - 2;
			pairs.push_back(temp);
		}

		for (int j = 3; j <= n / 2; j = j + 2)
		{
			if (isPrime[j] && isPrime[n - j])
			{
				IntPair temp;
				temp.first = j;
				temp.second = n - j;
				pairs.push_back(temp);
			}
		}

		cout << n << " has " << pairs.size() << " representation(s)\n";
		for (int j = 0; j < pairs.size(); j++)
		{
			cout << pairs[j].first << "+" << pairs[j].second << endl;
		}
	}
	return 0;
}