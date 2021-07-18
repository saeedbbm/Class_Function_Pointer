#include "class1.h"

class1::class1(QObject *parent) : QObject(parent)
//class1::class1(QObject *parent, QString var1) : QObject(parent)
{
    qDebug() << this << "construction";
}


class1::~class1()
{
    qDebug() << this << "deconstruction";
}

void class1::FuncName1(QString var11)
{
    qDebug() << this << var11 << "function" << number;
}

void class1::FuncName2(QString var22)
{
    qDebug() << this << var22 << "function by pointer";
}
