#pragma once
#include "Interval.h"
#include "Function.h"
#include "Method.h"

class NewtonMethod : public Method
{
	double x0;

public:
	NewtonMethod(Function function, Interval interval, double precision, double x0 = 0) : Method(function, interval, precision), x0(x0) { }

	double FindZeroInInterval() const;
	void SetX0(double x);
};

