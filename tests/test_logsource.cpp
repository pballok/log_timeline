#include "catch/catch.hpp"

#include "logsource.h"

SCENARIO("Adding lines to a LogSource", "[LogSource]")
{
  GIVEN("An empty LogSource with no lines")
  {
    LogSource ls(std::regex("timeregex"));

    REQUIRE(ls.lineCount() == 0);

    WHEN("three new lines are added")
    {
      ls.addLine("2017-01-27 17:34:29.346 INFO My First Log Line");
      ls.addLine("2017-01-27 17:34:30.378 INFO My Second Log Line");
      ls.addLine("2017-01-27 17:34:31.592 INFO My Third Log Line");

      THEN("the number of lines should be three")
      {
        REQUIRE(ls.lineCount() == 3);
      }
    }
  }
}
