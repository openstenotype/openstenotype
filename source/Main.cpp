#include <opensteno/Opensteno.hpp>
#include <thread>

using namespace opensteno;

int main(int argc, char **argv)
{
  Opensteno opensteno;

  while(opensteno.isRunning()) {
    opensteno.driver.update();
  }
  return 0;
}
