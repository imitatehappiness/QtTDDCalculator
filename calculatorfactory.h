#ifndef CALCULATORFACTORY_H
#define CALCULATORFACTORY_H


class CalculatorFactory
{
public:
    CalculatorFactory();
    virtual double addition(double, double) const = 0;
    virtual double subtraction(double, double) const = 0;
    virtual double multiplication(double, double) const = 0;
    virtual double division(double, double) const = 0;
    virtual double remainder (double, double) const = 0;
};

#endif // CALCULATORFACTORY_H
