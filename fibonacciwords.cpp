#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fib;
int number;
string bitPattern;

string convertToBits(int n)
{
	fib[0] = "0";
	fib[1] = "1";
	for (int i = 2; i <= n; i = i + 1)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n];
}

void getInput()
{
	cin >> number;
	cin.ignore(1000, '\n');
	for (int i = 0; i <= number; i = i + 1)
	{
		fib.push_back("0");
	}
	getline(cin, bitPattern);
}

int main()
{
	getInput();;
	string binN = convertToBits(number);

	int count = 0;
	for (int i = 0; i < binN.size() - bitPattern.size() + 1; i = i + 1)
	{
		if (binN.substr(i, bitPattern.size()) == bitPattern)
		{
			count = count + 1;
		}
	}
	cout << count << endl;

	return 0;
}