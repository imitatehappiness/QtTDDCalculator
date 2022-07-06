#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    setInterface();
    calculator = new StandartCaclulatorFactory();
    initConnect();
}

MainWindow::~MainWindow(){
    delete ui;
    delete calculator;
}

void MainWindow::setInterface(){

    QVector<QPair<QString, int>> captionNumbers = {{ "7", idButton::seven }, { "8", idButton::eight }, { "9", idButton::nine  },
                                                   { "4", idButton::four  }, { "5", idButton::five  }, { "6", idButton::six   },
                                                   { "1", idButton::one   }, { "2", idButton::two   }, { "3", idButton::three },
                                                   { "0", idButton::zero  }};

    QVector<QPair<QString, int>> captionOperation = {{ "CE",       idButton::clearAll       }, { "<",       idButton::clear       }, { "1/x", idButton::oneDevide   },
                                                     { "pow(x,y)", idButton::powY           }, { "sqrt(x)", idButton::sqrtY       }, { "/",   idButton::division    },
                                                     { "x",        idButton::multiplication }, { "-",       idButton::subtraction }, { "+",   idButton::addition    },
                                                     { "+/-",      idButton::reverseSign    }, { ".",       idButton::point       }, { "=",   idButton::getAnswer   }};

    const int COLUMN_BTN = 4;

    QGridLayout* gridScreen= new QGridLayout;
    QGridLayout* gridButtons = new QGridLayout;

    ui->w_screen->setLayout(gridScreen);
    ui->w_buttons->setLayout(gridButtons);

    QFont FontObj;
    FontObj.setBold(1);
    FontObj.setPixelSize(14);

    /// Buttons numbers
    for(int btnIndex = 0; btnIndex < captionNumbers.size(); btnIndex++){
        QPushButton *button = new QPushButton(this);
        button->setText(captionNumbers[btnIndex].first);
        button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        button->setProperty("id", captionNumbers[btnIndex].second);

        button->setFont(FontObj);
        gridButtons->addWidget(button, captionNumbers[btnIndex].second / COLUMN_BTN, captionNumbers[btnIndex].second % COLUMN_BTN);

        buttons.append(QPair<int, QPushButton*>(captionNumbers[btnIndex].second, button));
    }

    /// Buttons operations
    for(int operationIndex = 0; operationIndex < captionOperation.size(); operationIndex++){
        QPushButton *button = new QPushButton(this);
        button->setText(captionOperation[operationIndex].first);
        button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        button->setProperty("id", captionOperation[operationIndex].second);

        button->setFont(FontObj);
        gridButtons->addWidget(button, captionOperation[operationIndex].second / COLUMN_BTN, captionOperation[operationIndex].second % COLUMN_BTN);

        buttons.append(QPair<int, QPushButton*>(captionOperation[operationIndex].second, button));
    }

    /// Screen
    lineEditScreen = new QLineEdit(this);
    FontObj.setPixelSize(24);
    lineEditScreen->setFont(FontObj);
    lineEditScreen->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    lineEditScreen->setEnabled(0);
    lineEditScreen->setAlignment(Qt::AlignRight);
    gridScreen->addWidget(lineEditScreen);
}

void MainWindow::initConnect(){
    for(auto pb : buttons){
        connect(pb.second, SIGNAL(clicked()), SLOT(calculation()));
    }
}

void MainWindow::calculation(){
    QPushButton* button = (QPushButton*)(QObject::sender());
    uint idButton = button->property("id").toUInt();
    double result = 0;

    switch(idButton){
    case idButton::clearAll:        lineEditScreen->setText(calculator->clearAll()); break;
    case idButton::clear:           lineEditScreen->setText(calculator->clear(lineEditScreen->text())); break;
    case idButton::oneDevide:       lineEditScreen->setText(calculator->oneDevide(lineEditScreen->text())); break;
    case idButton::powY:            value = lineEditScreen->text(); lineEditScreen->setText(""); IdOperation =  idButton::powY; break;
    case idButton::sqrtY:           lineEditScreen->setText(calculator->sqrtY(lineEditScreen->text())); break;
    case idButton::division:        value = lineEditScreen->text(); lineEditScreen->setText(""); IdOperation =  idButton::division; break;
    case idButton::multiplication:  value = lineEditScreen->text(); lineEditScreen->setText(""); IdOperation =  idButton::multiplication; break;
    case idButton::subtraction:     value = lineEditScreen->text(); lineEditScreen->setText(""); IdOperation =  idButton::subtraction; break;
    case idButton::addition:        value = lineEditScreen->text(); lineEditScreen->setText(""); IdOperation =  idButton::addition; break;
    case idButton::reverseSign:     lineEditScreen->setText(calculator->reverseSign(lineEditScreen->text())); break;
    case idButton::point:           lineEditScreen->setText(calculator->point(lineEditScreen->text())); break;
    case idButton::getAnswer:       {
        QString result;
        if(IdOperation == idButton::division)       result = calculator->division(value, lineEditScreen->text());
        if(IdOperation == idButton::multiplication) result = calculator->multiplication(value, lineEditScreen->text());
        if(IdOperation == idButton::subtraction)    result = calculator->subtraction(value, lineEditScreen->text());
        if(IdOperation == idButton::addition)       result = calculator->addition(value, lineEditScreen->text());
        if(IdOperation == idButton::powY)           result = calculator->powY(value, lineEditScreen->text());
        IdOperation = -1;
        lineEditScreen->setText(result);
        break;
    }
    default: lineEditScreen->setText(calculator->addNum(lineEditScreen->text(), button->text())); break;
    }
}



