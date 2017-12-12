#include "catch/catch.hpp"

#include "logsource.h"

SCENARIO("Adding Log Lines to a LogSource", "[LogSource]")
{
  GIVEN("A LogSource with two Log Lines already in it") {
    LogSource ls;
    ls.addLogLine("2017-01-27 17:34:29.346 INFO My First Log Line");
    ls.addLogLine("2017-01-27 17:34:30.378 INFO My Second Log Line");

    REQUIRE(ls.logLineCount() == 2);

    WHEN("two additional lines are added") {
      ls.addLogLine("2017-01-27 17:34:39.346 INFO My Third Log Line");
      ls.addLogLine("2017-01-27 17:34:40.378 INFO My Fourth Log Line");

      THEN("the total number of lines should be 4") {
        REQUIRE(ls.logLineCount() == 4);
      }
    }
  }
}



SCENARIO("Adding Time Lines to a LogSource", "[LogSource]")
{
  GIVEN("A LogSource with two Time Lines already in it") {
    LogSource ls;
    ls.addTimeLine("TimeLine1");
    ls.addTimeLine("TimeLine2");

    REQUIRE(ls.timeLineCount() == 2);

    WHEN("two additional Time Lines are added") {
      ls.addTimeLine("TimeLine3");
      ls.addTimeLine("TimeLine4");

      THEN("the total number of Time Lines should be 4") {
        REQUIRE(ls.timeLineCount() == 4);
      }
    }
  }
}



SCENARIO("Adding Time Line Events to a LogSource", "[LogSource]")
{
  GIVEN("A LogSource with two Time Line Events already in it") {
    LogSource ls;
    ls.addTimeLineEvent("Event1", std::regex("regex1"));
    ls.addTimeLineEvent("Event2", std::regex("regex2"));

    REQUIRE(ls.timeLineEventCount() == 2);

    WHEN("two additional Time Line Events are added") {
      bool result1 = ls.addTimeLineEvent("Event3", std::regex("regex3"));
      bool result2 = ls.addTimeLineEvent("Event4", std::regex("regex4"));

      THEN("the total number of Time Line Events should be 4") {
        REQUIRE(ls.timeLineEventCount() == 4);
        REQUIRE(result1);
        REQUIRE(result2);
      }
    }

    WHEN("additional Time Line Event with already existing name is added") {
      bool result = ls.addTimeLineEvent("Event1", std::regex("regex5"));

      THEN("adding the Time Line Event should fail") {
        REQUIRE(ls.timeLineEventCount() == 2);
        REQUIRE_FALSE(result);
      }
    }
  }
}
