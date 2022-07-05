#ifndef CALCULATORFACTORY_H
#define CALCULATORFACTORY_H

#include "QString"
#include "structs.h"

class CalculatorFactory
{
public:
    CalculatorFactory() = default;
    virtual ~CalculatorFactory() = default;

    virtual QString addition(QString, QString) const = 0;
    virtual QString subtraction(QString, QString) const = 0;
    virtual QString multiplication(QString, QString) const = 0;
    virtual QString division(QString, QString) const = 0;
    virtual QString remainder (QString, QString) const = 0;
    virtual QString point(QString) = 0;
    virtual QString addNum(QString, QString) = 0;
    virtual QString reverseSign(QString) const = 0;
    virtual QString oneDevide(QString) const = 0;
    virtual QString clear(QString) const = 0;
    virtual QString clearAll() const = 0;
    virtual QString pow2(QString) const = 0;
    virtual QString sqrt2(QString) const = 0;
};

#endif // CALCULATORFACTORY_H
