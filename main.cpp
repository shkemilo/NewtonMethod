#include <iostream>
#include <cmath>
#include <iomanip>

#include "NewtonMethod.h"

using namespace std;

double f(double x)
{
	return exp(-x * x) - cos(x) - 1;
}

double fd(double x)
{
	return sin(x) - 2 * x * exp(-x * x);
}

int main()
{
	Function f(f, fd);

	Interval interval;
	cout << "Enter the interval in which the solution should be found: " << endl;
	cin >> interval;

	int precision;
	cout << "Enter the number of decimals of the solution: ";
	cin >> precision;

	double step;
	cout << "Enter the step of the first assumed x0: ";
	cin >> step;

	for (double i = interval.a; interval.IsInInterval(i); i += step)
	{
		NewtonMethod nm(f, interval, 5 * pow(10, -(precision + 1)), i);
		
		cout.unsetf(ios_base::fixed);
		cout << "For x0 = " << i << ": " << endl;
		try
		{
			cout << fixed << setprecision(precision) << nm.FindZeroInInterval() << endl;
		}
		catch (logic_error & e)
		{
			cout << e.what() << endl;
		}
		catch (runtime_error & e)
		{
			cout << e.what() << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}