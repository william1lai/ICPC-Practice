#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	for (int i = 0; i < ncases; i++)
	{
		int num;
		cin >> num;
		if (num % 2 == 0)
			cout << num << " is even\n";
		else
			cout << num << " is odd\n";
	}
	return 0;
}