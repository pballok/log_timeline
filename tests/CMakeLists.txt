set(LTL_SOURCES
  ../src/logline.cpp
  ../src/logsource.cpp
  ../src/timeline.cpp
)

include_directories(../include)

add_executable(ltlUnitTests
  ${LTL_SOURCES}
  test_main.cpp
  test_logline.cpp
  test_logsource.cpp
  test_timeline.cpp
)

add_test(NAME LTLUnitTests COMMAND ltlUnitTests)
