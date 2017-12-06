set(LTL_SOURCES
  ../src/logline.cpp
  ../src/logsource.cpp
)

include_directories(../include)

add_executable(ltlUnitTests
  ${LTL_SOURCES}
  test_main.cpp
  test_logline.cpp
  test_logsource.cpp
)

add_test(NAME LTLUnitTests COMMAND ltlUnitTests)
