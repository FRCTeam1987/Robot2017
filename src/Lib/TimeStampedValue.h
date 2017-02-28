/*
 * TimeStampedValue.h
 *
 *  Created on: Feb 25, 2017
 *      Author: Team 1987
 */

#ifndef TIMESTAMPEDVALUE_H_
#define TIMESTAMPEDVALUE_H_

#include <string>

class TimeStampedValue {
private:
	double m_timeStamp;
	double m_value1;
	double m_value2;
	double m_value3;
public:
	TimeStampedValue(double value1, double value2=0, double value3=0);
	virtual ~TimeStampedValue();
	double GetTimeStamp();
	double GetValue1();
	double GetValue2();
	double GetValue3();
	void UpdateTimeStamp();
	void SetTimeStamp(double timeStamp);
	void SetValue1(double value);
	void SetValue2(double value);
	void SetValue3(double value);
	std::string ToString();
};

#endif /* TIMESTAMPEDVALUE_H_ */
