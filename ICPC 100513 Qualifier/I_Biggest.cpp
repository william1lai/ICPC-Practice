#include <iostream>
#include "stdio.h"
#include <cmath>
#include <algorithm>

using namespace std;

const int totaldegs = 360*60*60;
const long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148;

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 0; i < ncases; i++)
	{
		long double r;
		int ppl;
		int degs;
		int mins;
		int secs;
		cin >> r >> ppl >> degs >> mins >> secs;

		int slicedegs = degs*3600 + mins*60 + secs;

		int* cuts = new int[ppl];
		cuts[0] = 0;
		int temp = 0;
		for (int j = 1; j < ppl; j++)
		{
			temp = (temp + slicedegs) % totaldegs;
			cuts[j] = temp;
		}

		sort(cuts, cuts + ppl);

		int max = 0;
		for (int j = 0; j < ppl - 1; j++)
		{
			if (cuts[j + 1] - cuts[j] > max)
				max = cuts[j + 1] - cuts[j];
		}
		if (totaldegs - cuts[ppl - 1] > max)
			max = totaldegs - cuts[ppl - 1];

		int biggestdegs = max;

		long double frac = (long double)biggestdegs / totaldegs;

		printf("%.6f\n", r*r*PI*frac);
	}
	return 0;
}