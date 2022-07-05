#ifndef STANDARTCACLULATORFACTORY_H
#define STANDARTCACLULATORFACTORY_H
#include "QString"
#include "QDebug"
#include "cmath"
#include "calculatorfactory.h"
#include "structs.h"
class StandartCaclulatorFactory : public CalculatorFactory
{
public:
    StandartCaclulatorFactory(){}
    ~StandartCaclulatorFactory(){}

    virtual QString addition(QString first, QString second) const;
    virtual QString subtraction(QString first, QString second) const;
    virtual QString multiplication(QString first, QString second) const;
    virtual QString division(QString first, QString second) const;
    virtual QString remainder (QString first, QString second) const;
    virtual QString point(QString num);
    virtual QString addNum(QString num, QString bntNum);
    virtual QString reverseSign(QString num)const;
    virtual QString oneDevide(QString num) const;
    virtual QString clear(QString num) const;
    virtual QString clearAll() const;
    virtual QString pow2(QString num) const;
    virtual QString sqrt2(QString num) const;


};
#endif // STANDARTCACLULATORFACTORY_H
