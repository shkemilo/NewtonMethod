#pragma once
#include <iostream>

#include "Interval.h"

typedef double (*func)(double);

class Function
{
	func function;
	func derivedFunction;

public:
	Function(func function, func derivedFunction = nullptr) : function(function), derivedFunction(derivedFunction){ }

	void SetFunction(func f);
	void SetDerviedFunction(func df);

	double GetValue(double x) const;
	double GetDerivedValue(double x) const;

	double operator()(double x) const;

	bool IsZeroInInterval(Interval i) const;
	bool IsDerivedFunctionDefined() const;
};

