#include "logsource.h"

LogSource::LogSource(std::regex timestampRegEx)
  : timestampRegEx_(std::move(timestampRegEx))
{

}

LogSource::~LogSource()
{

}

void LogSource::addLine(const std::string&) noexcept
{

}

std::size_t LogSource::lineCount() const noexcept
{
  return 0;
}
