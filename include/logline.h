#include <string>

class LogLine
{
public:
  LogLine(std::string rawLine);
  LogLine(const LogLine& other) = delete;
  LogLine(LogLine&& other) = delete;
  LogLine& operator =(const LogLine& other) = delete;
  LogLine& operator =(LogLine&& other) = delete;
  virtual ~LogLine();

  std::string rawLine() const noexcept;

private:
  std::string rawLine_;
};
