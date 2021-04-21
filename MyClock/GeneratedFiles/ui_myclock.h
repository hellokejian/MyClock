/********************************************************************************
** Form generated from reading UI file 'myclock.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLOCK_H
#define UI_MYCLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClockClass
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;

    void setupUi(QMainWindow *MyClockClass)
    {
        if (MyClockClass->objectName().isEmpty())
            MyClockClass->setObjectName(QStringLiteral("MyClockClass"));
        MyClockClass->resize(294, 64);
        centralWidget = new QWidget(MyClockClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(0, 0, 291, 61));
        lcdNumber->setDigitCount(8);
        MyClockClass->setCentralWidget(centralWidget);

        retranslateUi(MyClockClass);

        QMetaObject::connectSlotsByName(MyClockClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyClockClass)
    {
        MyClockClass->setWindowTitle(QApplication::translate("MyClockClass", "MyClock", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClockClass: public Ui_MyClockClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLOCK_H
