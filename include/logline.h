#ifndef LOGLINE_H
#define LOGLINE_H

#include <string>

class LogLine
{
public:
  LogLine(std::string rawLine) : rawLine_(std::move(rawLine)) {}
  LogLine(const LogLine& other) noexcept : rawLine_(other.rawLine_) {}
  LogLine(LogLine&& other) noexcept : rawLine_(std::move(other.rawLine_)) {}
  LogLine& operator =(const LogLine& other) = delete;
  LogLine& operator =(LogLine&& other) = delete;
  ~LogLine() {};

  std::string rawLine() const noexcept;

private:
  std::string rawLine_;
};

#endif
