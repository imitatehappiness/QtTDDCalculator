#include "mainwindow.h"

#include <QApplication>
#include <QProxyStyle>
#include <QStyleFactory>
#include <QFile>
#include <QDebug>
#include "TDD.h"

#define TEST
const QString FONT_FAMILY_APP = "Times";
const uint FONT_SIZE_APP = 9;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    a.setStyle(new QProxyStyle(QStyleFactory::create("Fusion")));
    a.setFont(QFont(FONT_FAMILY_APP, FONT_SIZE_APP));

    QFile styleFile(":/appstyles.qss");
    styleFile.open(QFile::ReadOnly);
    QString styleQSS = styleFile.readAll();

    a.setStyleSheet(styleQSS);

#ifdef TEST
    QTest::qExec(new TDDTest, argc, argv);
#else
    MainWindow w;
    w.show();
#endif
    return a.exec();
}



