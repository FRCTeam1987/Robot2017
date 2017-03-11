#ifndef ROBOLOG_H
#define ROBOLOG_H

#include <string>
#include <vector>

class RoboLog
{
public:
	void AddEntry(const char *msg);
	void DumpEntries(void);

protected:
	struct LOGENTRY
	{
		std::string Msg;
		double Timestamp;
	};
	typedef std::vector<LOGENTRY> LOGVEC;

	LOGVEC m_Log;
};

#endif // end of ROBOLOG_H
