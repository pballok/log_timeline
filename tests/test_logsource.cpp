#include "catch/catch.hpp"

#include "logsource.h"

TEST_CASE("Log Source", "Add Line")
{
  LogSource ls(std::regex("timeregex"));

  ls.addLine("2017-01-27 17:34:29.346 INFO My First Log Line");
  ls.addLine("2017-01-27 17:34:30.378 INFO My First Log Line");
  ls.addLine("2017-01-27 17:34:31.592 INFO My First Log Line");

  REQUIRE(ls.lineCount() == 3);
}
