#include "logsource.h"

void LogSource::addLine(const std::string& rawLine) noexcept
{
  logLines_.emplace_back(rawLine);
}

std::size_t LogSource::lineCount() const noexcept
{
  return logLines_.size();
}
