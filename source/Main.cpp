#include <opensteno/Opensteno.hpp>

using namespace opensteno;

int main(void)
{
  Opensteno opensteno;
  while(opensteno.isRunning()) {
    opensteno.driver.update();
  }
}
