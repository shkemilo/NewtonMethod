#include "NewtonMethod.h"

#include <iostream>
#include <cmath>
#include <string>

double NewtonMethod::FindZeroInInterval() const
{
	if (function.IsDerivedFunctionDefined() == false)
		throw std::runtime_error("Invalid function definition: No derived function defined");

	double prev, x = x0;
	do
	{
		prev = x;

		double derivedValue = function.GetDerivedValue(x);
		if (derivedValue == 0)
			throw std::logic_error("Invalid starting point x0: Slope goes to infinity");

		x = x - function(x) / derivedValue;
	} while ((abs(x - prev)) >= precision);

	if (!interval.IsInInterval(x))
	{
		throw std::logic_error("Soulution out of interval: x = " + std::to_string(x));
	}

	return x;
}

void NewtonMethod::SetX0(double x)
{
	x0 = x;
}
