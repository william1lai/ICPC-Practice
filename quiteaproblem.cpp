
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
	char line[80];

	for (int i = 0; i < 1000; i = i + 1)
	{
		cin.getline(line, 80);

		for (int i = 0; i < sizeof(line); i = i + 1)
		{
			line[i] = tolower(line[i]);
		}

		char word[80];

		int i = 0;
		while (! isspace(line[i]))
		{
			
			i = i + 1;
		}
		//word has been processed

		string key ("problem");

		if (strcmp(word, key.c_str()))
		{
			cout << "Yes" << endl;
			break;
		}
		cout << "No" << endl;
	}

	return 0;
}