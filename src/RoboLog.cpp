#include "RoboLog.h"

#include <WPILib.h>

void RoboLog::AddEntry(const char *msg)
{
	LOGENTRY log;

	log.Timestamp = frc::Timer::GetFPGATimestamp();
	log.Msg = msg;

	m_Log.push_back(log);
}

void RoboLog::DumpEntries()
{
	for(LOGVEC::size_type i=0; i<m_Log.size(); i++)
	{
		printf("Log: %10.6f  %s\n", m_Log[i].Timestamp, m_Log[i].Msg.c_str());
	}
}
