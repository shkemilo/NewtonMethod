#include "Method.h"

Function& Method::GetFunction()
{
	return function;
}

Interval& Method::GetInterval()
{
	return interval;
}

void Method::SetPrecision(double p)
{
	precision = p;
}
