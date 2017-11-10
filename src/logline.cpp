#include "logline.h"

LogLine::LogLine(std::string rawLine) : rawLine_(std::move(rawLine)) {

}

LogLine::~LogLine() {

}

std::string LogLine::rawLine() const noexcept {
  return rawLine_;
}
