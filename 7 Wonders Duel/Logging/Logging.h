#pragma once
#include<ostream>

#ifdef LOGGING_EXPORTS

#define API_LOGGER  __declspec(dllexport)
#else
#define API_LOGGER  __declspec(dllimport)
#endif // LOGGING_EXPORTS

class API_LOGGER Logging
{
public:
	enum class Level
	{
		Debug, Info, Warning, Error
	};

public:
	Logging(std::ostream& out, Level minLogLevel = Level::Warning);
	void Log(const std::string& message, Level level);

private:
	std::ostream& m_out;
	Level m_minLogLevel;
};