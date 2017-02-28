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
		return TimeStampedValue(0);	// might want a better default return value
	}
	double currentTime = Timer::GetFPGATimestamp();
	for(int i=historySize-1; i>0; i--) {
		if(m_history[i].GetTimeStamp() == currentTime) {
			return m_history[i];
		} else if (m_history[i].GetTimeStamp() < currentTime) {
			GetInterpolatedValue(i, i+1, timeStamp);
		}
	}
	return TimeStampedValue(0); // none found! might want a better default value
}

TimeStampedValue TimeStampedHistory::GetInterpolatedValue(TimeStampedValue timeStampedValue1, TimeStampedValue timeStampedValue2, double targetTimeStamp) {
	double deltaTimeStamp = targetTimeStamp - timeStampedValue1.GetTimeStamp();
	double deltaValue = timeStampedValue2.GetValue1() - timeStampedValue1.GetValue1();
	double deltaXValue = timeStampedValue2.GetTimeStamp() - timeStampedValue1.GetTimeStamp();

	double targetValue1 = ((deltaTimeStamp * deltaValue) / deltaXValue) + timeStampedValue1.GetTimeStamp();

	double targetValue2 = 0;
	double targetValue3 = 0;

	if (timeStampedValue2.GetValue2() != 0 && timeStampedValue1.GetValue2() != 0) {
		deltaTimeStamp = targetTimeStamp - timeStampedValue1.GetTimeStamp();
		deltaValue = timeStampedValue2.GetValue2() - timeStampedValue1.GetValue2();
		deltaXValue = timeStampedValue2.GetTimeStamp() - timeStampedValue1.GetTimeStamp();

		double targetValue2 = ((deltaTimeStamp * deltaValue) / deltaXValue) + timeStampedValue1.GetTimeStamp();

	}

	if (timeStampedValue2.GetValue3() != 0 && timeStampedValue1.GetValue3() != 0) {
		deltaTimeStamp = targetTimeStamp - timeStampedValue1.GetTimeStamp();
		deltaValue = timeStampedValue2.GetValue3() - timeStampedValue1.GetValue3();
		deltaXValue = timeStampedValue2.GetTimeStamp() - timeStampedValue1.GetTimeStamp();

		double targetValue3 = ((deltaTimeStamp * deltaValue) / deltaXValue) + timeStampedValue1.GetTimeStamp();

	}

	TimeStampedValue interpolatedValue = TimeStampedValue(targetValue1, targetValue2, targetValue3);
	interpolatedValue.SetTimeStamp(targetTimeStamp);
	return interpolatedValue;
}
