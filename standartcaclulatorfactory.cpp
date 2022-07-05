#include "standartcaclulatorfactory.h"

StandartCaclulatorFactory::StandartCaclulatorFactory(){

}

double StandartCaclulatorFactory::addition(double first, double second) const{
    return first + second;
}

double StandartCaclulatorFactory::subtraction(double first, double second) const{
    return first - second;
}

double StandartCaclulatorFactory::multiplication(double first, double second) const{
    return first * second;
}

double StandartCaclulatorFactory::division(double first, double second) const{
    return first / second;
}

double StandartCaclulatorFactory::remainder(double first, double second) const{
    return static_cast<int>(first) % static_cast<int>(second);
}
