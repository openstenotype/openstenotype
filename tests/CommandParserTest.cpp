#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include <catch.hpp>
#include <opensteno/CommandParser.hpp>
#include <stdexcept>

using namespace opensteno;

struct CommandParserFixtures
{
  CommandParser * parser;

  CommandParserFixtures() {
    //    parser = new CommandParser();
  }

  ~CommandParserFixtures() {}

};
TEST_CASE_METHOD(CommandParserFixtures, "Commands can be extracted", "[command-parser]") {
  SECTION("Just text") {
    REQUIRE(true);
  }
  SECTION("Modifier") {
    REQUIRE(true);
  }
  SECTION("Glue Command") {
    REQUIRE(true);
  }
}
