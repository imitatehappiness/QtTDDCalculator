#include "standartcaclulatorfactory.h"

QString StandartCaclulatorFactory::addition(QString first, QString second) const{
     return QString::number( first.toDouble() + second.toDouble(), 'g', 15 );
}

QString StandartCaclulatorFactory::subtraction(QString first, QString second) const{
     return QString::number( first.toDouble() - second.toDouble(), 'g', 15  );
}

QString StandartCaclulatorFactory::multiplication(QString first, QString second) const{
     return QString::number( first.toDouble() * second.toDouble(), 'g', 15  );
}

QString StandartCaclulatorFactory::division(QString first, QString second) const{
    return QString::number( first.toDouble() / second.toDouble(), 'g', 15  );
}

QString StandartCaclulatorFactory::remainder(QString first, QString second) const{
    return QString::number( static_cast<int>(first.toDouble()) % static_cast<int>(second.toDouble()), 'g', 15  );
}

QString StandartCaclulatorFactory::point(QString num) {
    if(!num.contains('.')){
        num += ".";
    }
    return num;
}

QString StandartCaclulatorFactory::addNum(QString num, QString bntNum) {
    return (num + bntNum);
}

QString StandartCaclulatorFactory::reverseSign(QString num) const{
    return QString::number(num.toDouble() * (-1), 'g', 15 );
}

QString StandartCaclulatorFactory::oneDevide(QString num) const{
    return QString::number(static_cast<double>(1) / num.toDouble(), 'g', 15 );
}

QString StandartCaclulatorFactory::clear(QString num) const{
    if(num.size() > 0){
        num.resize(num.size() - 1);
    }
    return num;
}

QString StandartCaclulatorFactory::clearAll() const{
    return "";
}

QString StandartCaclulatorFactory::pow2(QString num) const{
    return QString::number(num.toDouble() * num.toDouble(), 'g', 15 );
}

QString StandartCaclulatorFactory::sqrt2(QString num) const{
    return QString::number(sqrt(num.toDouble()), 'g', 15 );
}
