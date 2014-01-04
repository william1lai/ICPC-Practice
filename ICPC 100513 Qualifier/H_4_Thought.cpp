#include <iostream>
#include <vector>

using namespace std;

struct Solution
{
	int ans;
	char op1;
	char op2;
	char op3;
};

char getOp(int i)
{
	if (i == 0)
		return '+';
	if (i == 1)
		return '-';
	if (i == 2)
		return '*';
	if (i == 3)
		return '/';
	return ' ';
}

bool priority(char c)
{
	return (c == '*' || c == '/');
}

int subeval(char op, int a, int b)
{
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a*b;
	if (op == '/')
		return a/b;
	return 0;
}

int evaluate(char op1, char op2, char op3)
{
	if (priority(op1))
	{
		if (priority(op2))
		{
			int sans = subeval(op2, subeval(op1, 4, 4), 4);
			return subeval(op3, sans, 4);
		}
		else
		{
			if (priority(op3))
				return subeval(op2, subeval(op1, 4, 4), subeval(op3, 4, 4));
			else
				return subeval(op3, subeval(op2, subeval(op1, 4, 4), 4), 4);
		}
	}
	else
	{
		if (priority(op2))
		{
			if (priority(op3))
			{
				return subeval(op1, 4, subeval(op3, subeval(op2, 4, 4), 4));
			}
			else
			{
				return subeval(op3, subeval(op1, 4, subeval(op2, 4, 4)), 4);
			}
		}
		else
		{
			if (priority(op3))
			{
				return subeval(op2, subeval(op1, 4, 4), subeval(op3, 4, 4));
			}
			else
			{
				return subeval(op3, subeval(op2, subeval(op1, 4, 4), 4), 4);
			}
		}
	}
}

int main()
{
	vector<Solution> sols;

	for (int f = 0; f < 4; f++)
	{
		for (int s = 0; s < 4; s++)
		{
			for (int t = 0; t < 4; t++)
			{
				char op1 = getOp(f);
				char op2 = getOp(s);
				char op3 = getOp(t);

				int ans = evaluate(op1, op2, op3);

				Solution s;
				s.op1 = op1;
				s.op2 = op2;
				s.op3 = op3;
				s.ans = ans;

				sols.push_back(s);
			}
		}
	}

	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		int num;
		cin >> num;

		Solution s;

		bool found = false;
		for (int j = 0; j < sols.size(); j++)
		{
			if (sols[j].ans == num)
			{
				s = sols[j];
				found = true;
				break;
			}
		}

		if (found)
			cout << "4 " << s.op1 << " 4 " << s.op2 << " 4 " << s.op3 << " 4 = " << num << endl;
		else
			cout << "no solution\n";
	}
	return 0;
}			