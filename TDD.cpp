#include "TDD.h"

TDDTest::TDDTest() {
}

void TDDTest::addition_data(){
    QTest::addColumn<QString>("a");
    QTest::addColumn<QString>("b");
    QTest::addColumn<QString>("result");

    QTest::newRow("(10,1)") << "10" << "1" << "11";
    QTest::newRow("(-10,2)") << "-10" << "2" << "-8";
    QTest::newRow("(10.2,3)") << "10.2" << "3" << "13.2";
    QTest::newRow("(10,-4.1)") << "10" << "-4.1" << "5.9";
    QTest::newRow("(10,-100)") << "10" << "-100" << "-90";
}

void TDDTest::subtraction_data(){
    QTest::addColumn<QString>("a");
    QTest::addColumn<QString>("b");
    QTest::addColumn<QString>("result");

    QTest::newRow("(10,1)") << "10" << "1" << "9";
    QTest::newRow("(10,-2)") << "10" << "-2" << "12";
    QTest::newRow("(10,3.2)") << "10" << "3.2" << "6.8";
    QTest::newRow("(0,0)") << "0" << "0" << "0";
}

void TDDTest::multiplication_data(){
    QTest::addColumn<QString>("a");
    QTest::addColumn<QString>("b");
    QTest::addColumn<QString>("result");

    QTest::newRow("(10,1)") << "10" << "1" << "10";
    QTest::newRow("(10,-2)") << "10" << "-2" << "-20";
    QTest::newRow("(3.4,5.22)") << "3.4" << "5.22" << "17.748";
    QTest::newRow("(100,0)") << "100" << "0" << "0";
    QTest::newRow("(100,-123.3123)") << "100" << "-123.3123" << "-12331.23";
}

void TDDTest::addition() {
    QFETCH(QString, a);
    QFETCH(QString, b);
    QFETCH(QString, result);

    QCOMPARE(calulator.addition(a, b), result);
}

void TDDTest::subtraction() {
    QFETCH(QString, a);
    QFETCH(QString, b);
    QFETCH(QString, result);

    QCOMPARE(calulator.subtraction(a, b), result);
}

void TDDTest::multiplication(){
    QFETCH(QString, a);
    QFETCH(QString, b);
    QFETCH(QString, result);

    QCOMPARE(calulator.multiplication(a, b), result);
}
void TDDTest::division(){
    QCOMPARE(calulator.division("10","10"), "1");
}

void TDDTest::remainder(){
    QCOMPARE(calulator.division("33","10"), "3.3");
}
