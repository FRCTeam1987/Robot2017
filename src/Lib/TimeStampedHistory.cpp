/*
 * TimeStampedHistory.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: Team 1987
 */

#include <Lib/TimeStampedHistory.h>

#include "Timer.h"

TimeStampedHistory::TimeStampedHistory(int maxHistory) {
	// TODO Auto-generated constructor stub
	m_maxHistory = maxHistory;
}

TimeStampedHistory::~TimeStampedHistory() {
	// TODO Auto-generated destructor stub
}


void TimeStampedHistory::Add(TimeStampedValue value) {
	if(m_history.size() >= m_maxHistory) {
		m_history.erase(m_history.begin());
	}
	m_history.push_back(value);
}

TimeStampedValue TimeStampedHistory::GetHistory(double timeStamp) {
	int historySize = m_history.size();

	if(historySize <= 1) {	// Not enough history to look through!
		printf("size too small");
		return TimeStampedValue(0);	// might want a better default return value
	}

	double currentTimeStamp = Timer::GetFPGATimestamp();
	if(timeStamp > currentTimeStamp) {	// interpolate on a near future time
		return GetInterpolatedValue(m_history[historySize - 2], m_history[historySize - 1], timeStamp);
	}
	for(int i = historySize - 1; i>0; i--) {
		if(m_history[i].GetTimeStamp() == timeStamp) {

			return m_history[i];
		} else if (m_history[i].GetTimeStamp() < timeStamp) {

			return GetInterpolatedValue(m_history[i], m_history[i+1], timeStamp);
		}

	}
	printf("historySize 2 %d\n", historySize);

	return TimeStampedValue(0); // none found! might want a better default value
}

double TimeStampedHistory::Interpolate(double xGoal, double x1, double y1, double x2, double y2) {
	return y1 + (xGoal - x1) * ((y2 - y1) / (x2 - x1));
}

TimeStampedValue TimeStampedHistory::GetInterpolatedValue(TimeStampedValue timeStampedValue1, TimeStampedValue timeStampedValue2, double targetTimeStamp) {
	double targetValue1 = Interpolate(targetTimeStamp, timeStampedValue1.GetTimeStamp(), timeStampedValue1.GetValue1(), timeStampedValue2.GetTimeStamp(), timeStampedValue2.GetValue1());
	double targetValue2 = 0;
	double targetValue3 = 0;

	if (timeStampedValue2.GetValue2() != 0 && timeStampedValue1.GetValue2() != 0) {
		targetValue2 = Interpolate(targetTimeStamp, timeStampedValue1.GetTimeStamp(), timeStampedValue1.GetValue2(), timeStampedValue2.GetTimeStamp(), timeStampedValue2.GetValue2());
	}

	if (timeStampedValue2.GetValue3() != 0 && timeStampedValue1.GetValue3() != 0) {
		targetValue3 = Interpolate(targetTimeStamp, timeStampedValue1.GetTimeStamp(), timeStampedValue1.GetValue3(), timeStampedValue2.GetTimeStamp(), timeStampedValue2.GetValue3());
	}


	TimeStampedValue interpolatedValue = TimeStampedValue(targetValue1, targetValue2, targetValue3);
	interpolatedValue.SetTimeStamp(targetTimeStamp);
	return interpolatedValue;
}
