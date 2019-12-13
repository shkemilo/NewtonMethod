#pragma once
#include <iostream>

struct Interval
{
	double a;
	double b;

	Interval(double a = 0, double b = 0) : a(a), b(b) { }

	bool IsInInterval(double x) const
	{
		return (x >= a && x <= b);
	}

	friend std::istream& operator>>(std::istream& is, Interval& interval)
	{
		std::cout << "Enter lower bound: ";
		is >> interval.a;

		std::cout << "Enter upper bound: ";
		is >> interval.b;
		
		return is;
	}
};

