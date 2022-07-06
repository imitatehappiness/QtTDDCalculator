#include "TDD.h"

TDDTest::TDDTest() {
}

void TDDTest::addition_data(){
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
