#ifndef TIMELINE_H
#define TIMELINE_H

#include <string>

class TimeLine
{
public:
  explicit TimeLine(std::string timeLineName) : name_(std::move(timeLineName)) {}
  TimeLine(const TimeLine& other) noexcept : name_(other.name_) {}
  TimeLine(TimeLine&& other) noexcept : name_(std::move(other.name_)) {}
  TimeLine& operator =(const TimeLine& other) = delete;
  TimeLine& operator =(TimeLine&& other) = delete;
  ~TimeLine() {}

  std::string name() const noexcept { return name_; }

private:
  std::string name_;
};

#endif
