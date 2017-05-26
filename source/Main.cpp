#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include <QString>
#include <QStatusBar>
#include <QDockWidget>
#include <QDesktopWidget>
#include <QGridLayout>
#include <opensteno/Opensteno.hpp>
#include <thread>

using namespace opensteno;

void runUi(int argc, char **argv)
{
  QApplication app(argc, argv);
  QDesktopWidget widget;
  QRect mainScreenSize =
    widget.availableGeometry(widget.primaryScreen());
  QLabel* label = new QLabel("Opensteno");
  label->setGeometry( mainScreenSize.width()-1000, mainScreenSize.height() - 32,500,500 );
  label->setFixedSize( 1000, 32 );
  label->show();
  QString* style = new QString("QLabel {margin-left: 10}");
  app.setStyleSheet(*style);
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
