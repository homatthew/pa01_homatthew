// stats.cxx - implements statistician class as defined in stats.h
// Matthew Ho 2/9/18

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented

namespace main_savitch_2C
{
	statistician::statistician()
	{
		int count(0);
		double total = 0, tiniest = 0, largest = 0;
	}

	void statistician::next(double r)
	{
		count++;
		total++;
		if (count == 1)
		{
			tiniest = r;
			largest = r;
		}
		else
		{
			if (r < tiniest) tiniest = r;
			if (r > largest) largest = r;
		}	
	}

	void statistician::reset()
	{
		count = 0;
		total = 0;
		tiniest = 0;
		largest = 0;
	}

	double statistician::mean() const
	{
		return total / count;
	}

	double statistician::minimum() const
	{
		return tiniest;
	}

	double statistician::maximum() const
	{
		return largest;
	}

	statistician operator + (const statistician& s1, const statistician& s2)
	{
		statistician newStats;
		newStats.count = s1.count + s2.count;
		newStats.total = s2.total + s1.total;
		if (s1.tiniest <= s2.tiniest)
			newStats.tiniest = s1.tiniest;
		else
			newStats.tiniest = s2.tiniest;

		if (s1.largest >= s2.largest)
			newStats.largest = s1.largest;
		else
			newStats.largest = s2.largest;
		
		return newStats;
	}

	statistician operator *(double scale, const statistician& s2)
	{
		statistician newStats;
		newStats.count = s2.count;
		newStats.total = s2.total * scale;
		newStats.tiniest = s2.tiniest * scale;
		newStats.tiniest = s2.largest * scale;

		return newStats;
	}
	
	bool operator == (const statistician& s1, const statistician& s2)
	{
		if (s1.length() == s2.length())
		{
			if (s1.length() == 0) return true;

			return (s1.mean() == s2.mean() && s1.maximum() == s2.maximum() && s1.minimum() == s2.minimum());
		}
		else
			return false;	
	}
}
