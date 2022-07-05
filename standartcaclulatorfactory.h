#ifndef STANDARTCACLULATORFACTORY_H
#define STANDARTCACLULATORFACTORY_H

#include "calculatorfactory.h"
class StandartCaclulatorFactory : public CalculatorFactory
{
public:
    StandartCaclulatorFactory();
    virtual double addition(double first, double second) const;
    virtual double subtraction(double first, double second) const;
    virtual double multiplication(double first, double second) const;
    virtual double division(double first, double second) const;
    virtual double remainder (double first, double second) const;
};
#endif // STANDARTCACLULATORFACTORY_H
