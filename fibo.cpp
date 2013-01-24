#include <iostream>
#include <vector>

using namespace std;

vector <int> table;

int main()
{
	int n;
	cout << "Which fibonacci number to output? ";
	cin >> n;
	

	for (int i = 0; i < n; i = i + 1)
	{
		if (i == 0 || i == 1)
		{
			table.push_back(1);
		}
		else
		{
			table.push_back(table[i - 2] + table[i - 1]);
		}
	}

	cout << "Fibonacci # = " << table[n - 1] << endl;
	
	return 0;
}