#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	double b0, b1, b2, b3;
	double t0, t1, t2, t3;

	double db0 = b1; //derivative constant
	double db1 = 2 * b2; //derivative first term
	double db2 = 3 * b3; //derivative second term

	double xb1 = (-db1 + sqrt(db1*db1 - 4*db2*db0)) / db2;
	double xb2 = (-db1 - sqrt(db1*db1 - 4*db2*db0)) / db2;

	double dt0 = t1;
	double dt1 = 2 * t2;
	double dt2 = 3 * t3;

	double xt1 = (-dt1 + sqrt(dt1*dt1 - 4*dt2*dt0)) / dt2;
	double xt2 = (-dt1 + sqrt(dt1*dt1 - 4*dt2*dt0)) / dt2;

	double q1; //quality contribution of first
	double q2; //qul
	if ((xb1 <= 1) && (xb1 >= 0)) //if within boundaries
	{
		if ((xb2 <= 1 && (xb2 >= 0)) //if also within boundaries
		{



	double quality = (abs(xb1 - xb2) + abs(xt1 - xt2));

	cout << quality << endl;



	return 0;
}