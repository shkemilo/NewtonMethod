#pragma once
#include "Function.h"
#include "Interval.h"

class Method
{
protected:
	Function function;
	Interval interval;

	double precision;

	Method(Function function, Interval interval, double precision = 0.0001) : function(function), interval(interval), precision(precision) { }

public:
	Function& GetFunction();
	Interval& GetInterval();
	
	void SetPrecision(double p);
	virtual double FindZeroInInterval() const = 0;	
};

