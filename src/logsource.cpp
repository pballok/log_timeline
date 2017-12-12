#include "logsource.h"

void LogSource::addLogLine(const std::string& rawLine) noexcept
{
  logLines_.emplace_back(rawLine);
}

std::size_t LogSource::logLineCount() const noexcept
{
  return logLines_.size();
}

void LogSource::addTimeLine(const std::string& timeLineName) noexcept
{
  timeLines_.emplace_back(timeLineName);
}

std::size_t LogSource::timeLineCount() const noexcept
{
  return timeLines_.size();
}

bool LogSource::addTimeLineEvent(const std::string& timeLineEventName, const std::regex& pattern) noexcept
{
  auto result = timeLineEvents_.emplace(timeLineEventName, pattern);
  return result.second;
}

std::size_t LogSource::timeLineEventCount() const noexcept
{
  return timeLineEvents_.size();
}
