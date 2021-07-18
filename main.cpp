#include <QCoreApplication>
#include "class1.h"

int* FuncPtrArray()
{
    int* outputPtr = new int[4];
    outputPtr[0] = 0;
    outputPtr[1] = 1;
    outputPtr[2] = 2;
    return outputPtr;  // Points to the start of the array
}

int Func2(class1 &objPointer)
{
    objPointer.FuncName2("This is Func2");
    return objPointer.number;
}

void  FuncPtr(int &value1, int value2, int &value3)
{
    qDebug() << "Ptr Address: " << value1 << &value2 << &value3;
    qDebug() << "Ptr in Func 8: " << value1 << value2 << value3;
    value1 +=1;
    value2 +=1;
    value3 +=1;
}

// These are pointers
// &value1 is the address of the pointer itself not where it is pointing at
// value1 is the value inside the pointer which is the same as the address it is point at
//      value ~~ address of   ||  address ~~ value of
// value-*ptr ~~ &value-ptr || &value-ptr ~~ *value-*ptr

//int Func2(class1 *objPointer)
//{
//    objPointer->FuncName2("This is Func2");
//    return objPointer->number;
//}

//void  FuncPtr(int *value1, int value2, int *value3)
//{
//    qDebug() << "Ptr Address: " << value1 << &value2 << value3;
//    qDebug() << "Ptr in Func 8: " << *value1 << value2 << *value3;
//    *value1 +=1;
//    value2 +=1;
//    *value3 +=1;
//}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    class1 object1;
    object1.number = 8;
    object1.FuncName1("this is the variable");



    int varPtr1 = Func2(object1);       // Method 1 pass by reference
//    int varPtr1 = Func2(&object1);    // Method 2 pass by pointer

    int varPtr2 = varPtr1;
    int *varPtr3 = new int;
    *varPtr3 = varPtr1;
    qDebug() << "Func Output 8: " << varPtr1 << varPtr2 << *varPtr3 ;

// varPtr is sending the variable and &var is assigning var to the value of the given address - no pointer defined
// &varptr is sending the address and *var is assigning adress to var, *var is the value of the pointed address

    FuncPtr(varPtr1, varPtr2, *varPtr3);          // Method 1 pass by reference
//    FuncPtr(&varPtr1, varPtr2, varPtr3);       // Method 2 pass by pointer

    qDebug() << "Ptr after Func 9: " << varPtr1 << varPtr2 << *varPtr3;

    delete varPtr3;;

    int* ptrArr = FuncPtrArray();
    ptrArr[3]=3;
        for (int i = 0; i < 4; i++)
      {
             qDebug() << ptrArr[i];
      }

    delete[] ptrArr;        // Delete pointer
    ptrArr = nullptr;       // Delete pointer
    return a.exec();
}
