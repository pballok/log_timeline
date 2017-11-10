#include "catch/catch.hpp"

#include "logline.h"

TEST_CASE("Raw Line", "[LogLine]")
{
  LogLine ll("2017-08-02 17:59:38.123 Error: Something bad happened");

  REQUIRE(ll.rawLine() == "2017-08-02 17:59:38.123 Error: Something bad happened");
}
