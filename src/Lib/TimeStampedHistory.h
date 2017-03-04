/*
 * TimeStampedHistory.h
 *
 *  Created on: Feb 25, 2017
 *      Author: Team 1987
 */

#ifndef TIMESTAMPEDHISTORY_H_
#define TIMESTAMPEDHISTORY_H_
#include "TimeStampedValue.h"
#include <vector>

//using namespace std;

class TimeStampedHistory {
private:
	std::vector<TimeStampedValue> m_history;
	int m_maxHistory;
	TimeStampedValue GetInterpolatedValue(TimeStampedValue timeStampedValue1, TimeStampedValue timeStampedValue2, double targetTimeStamp);
public:
	TimeStampedHistory(int maxHistory);
	virtual ~TimeStampedHistory();
	double Interpolate(double xGoal, double x1, double y1, double x2, double y2);
	void Add(TimeStampedValue value);
	TimeStampedValue GetHistory(double timeStamp);
};

#endif /* TIMESTAMPEDHISTORY_H_ */
