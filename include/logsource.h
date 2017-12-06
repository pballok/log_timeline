#include <regex>

class LogSource
{
public:
  explicit LogSource(std::regex timestampRegEx);
  LogSource(const LogSource& other) = delete;
  LogSource(LogSource&& other) = delete;
  LogSource& operator =(const LogSource& other) = delete;
  LogSource& operator =(LogSource&& other) = delete;
  ~LogSource();

  void addLine(const std::string& rawLine) noexcept;
  std::size_t lineCount() const noexcept;

private:
  std::regex timestampRegEx_;
};
