#include "Logging.h"

Logging::Logging(std::ostream& out, Level minLogLevel) :m_out(out), m_minLogLevel(minLogLevel)
{
}

void Logging::Log(const std::string& message, Level level)
{
	if (level < m_minLogLevel)
		return;
	switch (level)
	{
	case Logging::Level::Debug:
	{
		m_out << "[Debug]";
		break;
	}case Logging::Level::Info:
	{
		m_out << "[Info]";
		break;
	}case Logging::Level::Warning:
	{
		m_out << "[Waring]";
		break;
	}case Logging::Level::Error:
	{
		m_out << "[Error]";
		break;
	}
	default:
		break;
	}
	m_out << message << std::endl;
	//m_out.flush();
}
