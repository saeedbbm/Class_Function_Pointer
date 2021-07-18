#ifndef CLASS1_H
#define CLASS1_H

#include <QObject>
// include QStuff that is used in class1.cpp
#include <QDebug>

class class1 : public QObject
{
    Q_OBJECT

public:

    //Constructor
    explicit class1(QObject *parent = nullptr);
    //explicit class1(QObject *parent = nullptr,  QString var1 = "");

    //Deconstructor
    ~class1();

    //Define Func
    void FuncName1(QString var1);
    void FuncName2(QString var2);       // Called in function that access class by pointer to object

    //Define Variable
    int number;

signals:

};

#endif // CLASS1_H
