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

TDDTest::TDDTest() {
}

inline void TDDTest::addition_data(){
    QTest::addColumn<QString>("a");
    QTest::addColumn<QString>("b");
    QTest::addColumn<QString>("result");

    QTest::newRow("test(10,1)") << "10" << "1" << "11";
    QTest::newRow("test(10,2)") << "10" << "2" << "12";
    QTest::newRow("test(10,3)") << "10" << "3" << "13";
    QTest::newRow("test(10,4)") << "10" << "4" << "14";
    QTest::newRow("test(10,5)") << "10" << "5" << "15";
    QTest::newRow("test(10,6)") << "10" << "6" << "16";
}

void TDDTest::addition() {
    QFETCH(QString, a);
    QFETCH(QString, b);
    QFETCH(QString, result);

    QCOMPARE(calulator.addition(a, b), result);
}

void TDDTest::subtraction() {
    QCOMPARE(calulator.subtraction("10","13"), "-3");
}

void TDDTest::multiplication(){
    QCOMPARE(calulator.multiplication("10","13"), "130");
}

void TDDTest::division(){
    QCOMPARE(calulator.division("10","10"), "1");
}

void TDDTest::remainder(){
    QCOMPARE(calulator.division("33","10"), "3.3");
}

#ifdef TEST
    QTEST_APPLESS_MAIN( TDDTest )
#endif

#endif // TDD_H
