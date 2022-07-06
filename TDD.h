#ifndef TDD_H
#define TDD_H

#include <QtTest>
#include <QString>

#include <standartcaclulatorfactory.h>

class TDDTest : public QObject {
    Q_OBJECT
public:
    TDDTest();
private:
    StandartCaclulatorFactory calulator;
private slots:
    void addition();
    void subtraction();
    void multiplication();
    void division();
    void remainder();
    void addition_data();
};

#endif // TDD_H
