#include "catch/catch.hpp"

#include "logline.h"

SCENARIO("Getting the raw line back", "[LogLine]")
{
  GIVEN("A LogLine containing a given line from a log") {
    LogLine ll("2017-08-02 17:59:38.123 Info: A sample log line");

    THEN("rawLine() should return with the same line") {
      REQUIRE(ll.rawLine() == "2017-08-02 17:59:38.123 Info: A sample log line");
    }
  }
}
