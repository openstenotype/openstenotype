#include <opensteno/Opensteno.hpp>
#include <opensteno/WindowSystem.hpp>
#include <opensteno/WindowSystemDriver.hpp>

using namespace opensteno;

int main(void)
{
  WindowSystem windowSystem;
  WindowSystemDriver windowSystemDriver(windowSystem);
  while(!windowSystemDriver.receivedShutdownCommand()) {
    windowSystemDriver.update();
  }
}
