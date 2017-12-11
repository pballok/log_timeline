#include "catch/catch.hpp"

#include "timeline.h"

SCENARIO("Getting the name back", "[TimeLine]")
{
  GIVEN("A TimeLine with a name")
  {
    TimeLine tl("Test TimeLine 1");

    THEN("name() should return with the same name")
    {
      REQUIRE(tl.name() == "Test TimeLine 1");
    }
  }
}
