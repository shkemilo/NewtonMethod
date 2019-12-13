#include "Function.h"
#include <iostream>

void Function::SetFunction(func f)
{
	if (f != nullptr)
		function = f;
}

void Function::SetDerviedFunction(func df)
{
	if (df != nullptr)
		derivedFunction = df;
}

double Function::GetValue(double x) const
{
	return function(x);
}

double Function::GetDerivedValue(double x) const
{
	if (derivedFunction != nullptr)
	{
		return derivedFunction(x);
	}
	else
		throw std::runtime_error("Runtime Error: Derived function not defined");
}

double Function::operator()(double x) const
{
	return function(x);
}

bool Function::IsZeroInInterval(Interval i) const
{
	return (function(i.a) * function(i.b) < 0);
}

bool Function::IsDerivedFunctionDefined() const
{
	return (derivedFunction != nullptr);
}
