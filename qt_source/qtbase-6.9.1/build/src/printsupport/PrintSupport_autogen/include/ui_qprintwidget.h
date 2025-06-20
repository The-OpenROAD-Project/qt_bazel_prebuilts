/********************************************************************************
** Form generated from reading UI file 'qprintwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPRINTWIDGET_H
#define UI_QPRINTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPrintWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *printerGroup;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *printers;
    QPushButton *properties;
    QLabel *label_2;
    QLabel *location;
    QCheckBox *preview;
    QLabel *label_3;
    QLabel *type;
    QLabel *lOutput;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filename;
    QToolButton *fileBrowser;

    void setupUi(QWidget *QPrintWidget)
    {
        if (QPrintWidget->objectName().isEmpty())
            QPrintWidget->setObjectName("QPrintWidget");
        QPrintWidget->resize(443, 175);
        horizontalLayout_2 = new QHBoxLayout(QPrintWidget);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        printerGroup = new QGroupBox(QPrintWidget);
        printerGroup->setObjectName("printerGroup");
        gridLayout = new QGridLayout(printerGroup);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(printerGroup);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        printers = new QComboBox(printerGroup);
        printers->setObjectName("printers");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(printers->sizePolicy().hasHeightForWidth());
        printers->setSizePolicy(sizePolicy);

        gridLayout->addWidget(printers, 0, 1, 1, 1);

        properties = new QPushButton(printerGroup);
        properties->setObjectName("properties");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(properties->sizePolicy().hasHeightForWidth());
        properties->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(properties, 0, 2, 1, 1);

        label_2 = new QLabel(printerGroup);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        location = new QLabel(printerGroup);
        location->setObjectName("location");

        gridLayout->addWidget(location, 1, 1, 1, 1);

        preview = new QCheckBox(printerGroup);
        preview->setObjectName("preview");

        gridLayout->addWidget(preview, 1, 2, 1, 1);

        label_3 = new QLabel(printerGroup);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        type = new QLabel(printerGroup);
        type->setObjectName("type");

        gridLayout->addWidget(type, 2, 1, 1, 1);

        lOutput = new QLabel(printerGroup);
        lOutput->setObjectName("lOutput");

        gridLayout->addWidget(lOutput, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        filename = new QLineEdit(printerGroup);
        filename->setObjectName("filename");

        horizontalLayout->addWidget(filename);

        fileBrowser = new QToolButton(printerGroup);
        fileBrowser->setObjectName("fileBrowser");

        horizontalLayout->addWidget(fileBrowser);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 2);


        horizontalLayout_2->addWidget(printerGroup);

#if QT_CONFIG(shortcut)
        label->setBuddy(printers);
        lOutput->setBuddy(filename);
#endif // QT_CONFIG(shortcut)

        retranslateUi(QPrintWidget);

        QMetaObject::connectSlotsByName(QPrintWidget);
    } // setupUi

    void retranslateUi(QWidget *QPrintWidget)
    {
        QPrintWidget->setWindowTitle(QCoreApplication::translate("QPrintWidget", "Form", nullptr));
        printerGroup->setTitle(QCoreApplication::translate("QPrintWidget", "Printer", nullptr));
        label->setText(QCoreApplication::translate("QPrintWidget", "&Name:", nullptr));
        properties->setText(QCoreApplication::translate("QPrintWidget", "P&roperties", nullptr));
        label_2->setText(QCoreApplication::translate("QPrintWidget", "Location:", nullptr));
        preview->setText(QCoreApplication::translate("QPrintWidget", "Preview", nullptr));
        label_3->setText(QCoreApplication::translate("QPrintWidget", "Type:", nullptr));
        lOutput->setText(QCoreApplication::translate("QPrintWidget", "Output &file:", nullptr));
        fileBrowser->setText(QCoreApplication::translate("QPrintWidget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QPrintWidget: public Ui_QPrintWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPRINTWIDGET_H
