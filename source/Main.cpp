#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include <QStatusBar>
#include <QDockWidget>
#include <opensteno/Opensteno.hpp>
#include <thread>

using namespace opensteno;

void runUi(int argc, char **argv)
{
  QApplication app(argc, argv);
  QLabel *label = new QLabel("Opensteno");
  label->setGeometry( 100,100,500,500 );
  label->show();
  app.exec();
}

int main(int argc, char **argv)
{
  Opensteno opensteno;
  std::thread uiThread(runUi, argc, argv);
  while(opensteno.isRunning()) {
    opensteno.driver.update();
  }
  QApplication::quit();
  uiThread.join();
  return 0;
}
