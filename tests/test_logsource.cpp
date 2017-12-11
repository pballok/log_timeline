#include "catch/catch.hpp"

#include "logsource.h"

SCENARIO("Adding Log Lines to a LogSource", "[LogSource]")
{
  GIVEN("An empty LogSource with no Log Lines")
  {
    LogSource ls;

    REQUIRE(ls.logLineCount() == 0);

    WHEN("three new Log Lines are added")
    {
      ls.addLogLine("2017-01-27 17:34:29.346 INFO My First Log Line");
      ls.addLogLine("2017-01-27 17:34:30.378 INFO My Second Log Line");
      ls.addLogLine("2017-01-27 17:34:31.592 INFO My Third Log Line");

      THEN("the total number of Log Lines should be 3")
      {
        REQUIRE(ls.logLineCount() == 3);
      }
    }
  }

  GIVEN("A LogSource with two Log Lines already in it")
  {
    LogSource ls;
    ls.addLogLine("2017-01-27 17:34:29.346 INFO My First Log Line");
    ls.addLogLine("2017-01-27 17:34:30.378 INFO My Second Log Line");

    REQUIRE(ls.logLineCount() == 2);

    WHEN("two additional lines are added")
    {
      ls.addLogLine("2017-01-27 17:34:39.346 INFO My Third Log Line");
      ls.addLogLine("2017-01-27 17:34:40.378 INFO My Fourth Log Line");

      THEN("the total number of lines should be 4")
      {
        REQUIRE(ls.logLineCount() == 4);
      }
    }
  }
}



SCENARIO("Adding Time Lines to a LogSource", "[LogSource]")
{
  GIVEN("An empty LogSource with no Time Lines")
  {
    LogSource ls;

    REQUIRE(ls.timeLineCount() == 0);

    WHEN("three new Time Lines are added")
    {
      ls.addTimeLine("TimeLine1");
      ls.addTimeLine("TimeLine2");
      ls.addTimeLine("TimeLine3");

      THEN("the total number of Time Lines should be 3")
      {
        REQUIRE(ls.timeLineCount() == 3);
      }
    }
  }

  GIVEN("A LogSource with two Time Lines already in it")
  {
    LogSource ls;
    ls.addTimeLine("TimeLine1");
    ls.addTimeLine("TimeLine2");

    REQUIRE(ls.timeLineCount() == 2);

    WHEN("two additional Time Lines are added")
    {
      ls.addTimeLine("TimeLine3");
      ls.addTimeLine("TimeLine4");

      THEN("the total number of Time Lines should be 4")
      {
        REQUIRE(ls.timeLineCount() == 4);
      }
    }
  }
}
