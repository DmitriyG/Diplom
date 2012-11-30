/********************************************************************************
** Form generated from reading UI file 'pole.ui'
**
** Created: Fri 30. Nov 01:17:21 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLE_H
#define UI_POLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pole
{
public:
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QListView *listView;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *pole)
    {
        if (pole->objectName().isEmpty())
            pole->setObjectName(QString::fromUtf8("pole"));
        pole->setWindowModality(Qt::WindowModal);
        pole->resize(163, 316);
        comboBox = new QComboBox(pole);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 141, 22));
        layoutWidget = new QWidget(pole);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 270, 141, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        listView = new QListView(pole);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 90, 141, 161));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);
        listView->setSelectionMode(QAbstractItemView::MultiSelection);
        label = new QLabel(pole);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(pole);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 111, 16));
        label_2->setFont(font);

        retranslateUi(pole);

        QMetaObject::connectSlotsByName(pole);
    } // setupUi

    void retranslateUi(QDialog *pole)
    {
        pole->setWindowTitle(QApplication::translate("pole", "\320\222\321\213\320\261\320\276\321\200 \320\277\320\276\320\273\320\265\320\271", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("pole", "Add", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("pole", "\320\222\321\213\320\261\320\276\321\200 \320\242\320\260\320\261\320\273\320\270\321\206\321\213:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("pole", "\320\222\321\213\320\261\320\276\321\200 \320\237\320\276\320\273\320\265\320\271:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class pole: public Ui_pole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLE_H
