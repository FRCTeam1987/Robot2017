/*
 * TimeStampedValue.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: Team 1987
 */

#include "TimeStampedValue.h"

#include "Timer.h"


#include <sstream>
#include <iomanip>
#include <sys/time.h>


TimeStampedValue::TimeStampedValue(double value1, double value2, double value3) {
	m_timeStamp = frc::Timer::GetFPGATimestamp();

	m_value1 = value1;
	m_value2 = value2;
	m_value3 = value3;
}

TimeStampedValue::~TimeStampedValue() {
}

double TimeStampedValue::GetTimeStamp() {
	return m_timeStamp;
}

double TimeStampedValue::GetValue1() {
	return m_value1;
}

double TimeStampedValue::GetValue2() {
	return m_value2;
}

double TimeStampedValue::GetValue3() {
	return m_value3;
}

void TimeStampedValue::UpdateTimeStamp() {
	SetTimeStamp(Timer::GetFPGATimestamp());
}

void TimeStampedValue::SetTimeStamp(double timeStamp) {
	m_timeStamp = timeStamp;
}

void TimeStampedValue::SetValue1(double value) {
	m_value1 = value;
}

std::string TimeStampedValue::ToString() {
	std::stringstream ss;

	ss << "Timestamp: " << std::setw(6) << std::setprecision(6) << GetTimeStamp() << ", ";
	ss << "Value1: " << std::setw(6) << std::setprecision(3) << GetValue1() << ", ";
	ss << "Value2: " << std::setw(6) << std::setprecision(3) << GetValue2() << ", ";
	ss << "Value3: " << std::setw(6) << std::setprecision(3) << GetValue3() << std::endl;

	return ss.str();
}
