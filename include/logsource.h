#ifndef LOGSOURCE_H
#define LOGSOURCE_H

#include <vector>
#include <regex>

#include "logline.h"
#include "timeline.h"

class LogSource
{
public:
  LogSource() {}
  LogSource(const LogSource& other) = delete;
  LogSource(LogSource&& other) = delete;
  LogSource& operator =(const LogSource& other) = delete;
  LogSource& operator =(LogSource&& other) = delete;
  ~LogSource() {}

  void addLogLine(const std::string& rawLine) noexcept;
  std::size_t logLineCount() const noexcept;

  void addTimeLine(const std::string& timeLineName) noexcept;
  std::size_t timeLineCount() const noexcept;

  bool addTimeLineEvent(const std::string& timeLineEventName, const std::regex& pattern) noexcept;
  std::size_t timeLineEventCount() const noexcept;

private:
  std::vector<LogLine> logLines_;
  std::vector<TimeLine> timeLines_;
  std::map<std::string, std::regex> timeLineEvents_;
};

#endif
