/********************************************************************************
** Form generated from reading UI file 'qprintsettingsoutput.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPRINTSETTINGSOUTPUT_H
#define UI_QPRINTSETTINGSOUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPrintSettingsOutput
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabs;
    QWidget *copiesTab;
    QHBoxLayout *horizontalLayout;
    QGroupBox *gbPrintRange;
    QVBoxLayout *_3;
    QRadioButton *printAll;
    QHBoxLayout *_4;
    QRadioButton *printRange;
    QSpinBox *from;
    QLabel *label_3;
    QSpinBox *to;
    QSpacerItem *spacerItem;
    QHBoxLayout *pagesLayout;
    QRadioButton *pagesRadioButton;
    QLineEdit *pagesLineEdit;
    QRadioButton *printCurrentPage;
    QRadioButton *printSelection;
    QHBoxLayout *_5;
    QLabel *pageSetLabel;
    QComboBox *pageSetCombo;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *copies;
    QSpacerItem *horizontalSpacer;
    QCheckBox *collate;
    QLabel *outputIcon;
    QCheckBox *reverse;
    QSpacerItem *verticalSpacer_2;
    QWidget *optionsTab;
    QGridLayout *gridLayout_2;
    QGroupBox *colorMode;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_6;
    QRadioButton *color;
    QLabel *colorIcon;
    QRadioButton *grayscale;
    QGroupBox *duplex;
    QVBoxLayout *verticalLayout;
    QRadioButton *noDuplex;
    QRadioButton *duplexLong;
    QRadioButton *duplexShort;
    QSpacerItem *verticalSpacer_42;

    void setupUi(QWidget *QPrintSettingsOutput)
    {
        if (QPrintSettingsOutput->objectName().isEmpty())
            QPrintSettingsOutput->setObjectName("QPrintSettingsOutput");
        QPrintSettingsOutput->resize(432, 251);
        horizontalLayout_2 = new QHBoxLayout(QPrintSettingsOutput);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabs = new QTabWidget(QPrintSettingsOutput);
        tabs->setObjectName("tabs");
        copiesTab = new QWidget();
        copiesTab->setObjectName("copiesTab");
        horizontalLayout = new QHBoxLayout(copiesTab);
        horizontalLayout->setObjectName("horizontalLayout");
        gbPrintRange = new QGroupBox(copiesTab);
        gbPrintRange->setObjectName("gbPrintRange");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbPrintRange->sizePolicy().hasHeightForWidth());
        gbPrintRange->setSizePolicy(sizePolicy);
        _3 = new QVBoxLayout(gbPrintRange);
        _3->setSpacing(4);
        _3->setObjectName("_3");
        _3->setContentsMargins(6, 6, 6, 6);
        printAll = new QRadioButton(gbPrintRange);
        printAll->setObjectName("printAll");
        printAll->setChecked(true);

        _3->addWidget(printAll);

        _4 = new QHBoxLayout();
        _4->setSpacing(6);
        _4->setObjectName("_4");
        _4->setContentsMargins(0, 0, 0, 0);
        printRange = new QRadioButton(gbPrintRange);
        printRange->setObjectName("printRange");

        _4->addWidget(printRange);

        from = new QSpinBox(gbPrintRange);
        from->setObjectName("from");
        from->setEnabled(false);
        from->setMinimum(1);
        from->setMaximum(999);

        _4->addWidget(from);

        label_3 = new QLabel(gbPrintRange);
        label_3->setObjectName("label_3");

        _4->addWidget(label_3);

        to = new QSpinBox(gbPrintRange);
        to->setObjectName("to");
        to->setEnabled(false);
        to->setMinimum(1);
        to->setMaximum(999);

        _4->addWidget(to);

        spacerItem = new QSpacerItem(0, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        _4->addItem(spacerItem);


        _3->addLayout(_4);

        pagesLayout = new QHBoxLayout();
        pagesLayout->setObjectName("pagesLayout");
        pagesRadioButton = new QRadioButton(gbPrintRange);
        pagesRadioButton->setObjectName("pagesRadioButton");

        pagesLayout->addWidget(pagesRadioButton);

        pagesLineEdit = new QLineEdit(gbPrintRange);
        pagesLineEdit->setObjectName("pagesLineEdit");
        pagesLineEdit->setEnabled(false);

        pagesLayout->addWidget(pagesLineEdit);


        _3->addLayout(pagesLayout);

        printCurrentPage = new QRadioButton(gbPrintRange);
        printCurrentPage->setObjectName("printCurrentPage");

        _3->addWidget(printCurrentPage);

        printSelection = new QRadioButton(gbPrintRange);
        printSelection->setObjectName("printSelection");

        _3->addWidget(printSelection);

        _5 = new QHBoxLayout();
        _5->setSpacing(6);
        _5->setObjectName("_5");
        _5->setContentsMargins(-1, -1, -1, 0);
        pageSetLabel = new QLabel(gbPrintRange);
        pageSetLabel->setObjectName("pageSetLabel");
        pageSetLabel->setVisible(false);

        _5->addWidget(pageSetLabel);

        pageSetCombo = new QComboBox(gbPrintRange);
        pageSetCombo->setObjectName("pageSetCombo");
        pageSetCombo->setVisible(false);

        _5->addWidget(pageSetCombo);


        _3->addLayout(_5);

        verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        _3->addItem(verticalSpacer);


        horizontalLayout->addWidget(gbPrintRange);

        groupBox = new QGroupBox(copiesTab);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        copies = new QSpinBox(groupBox);
        copies->setObjectName("copies");
        copies->setMinimum(1);
        copies->setMaximum(999);

        gridLayout->addWidget(copies, 0, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(91, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        collate = new QCheckBox(groupBox);
        collate->setObjectName("collate");

        gridLayout->addWidget(collate, 1, 0, 1, 2);

        outputIcon = new QLabel(groupBox);
        outputIcon->setObjectName("outputIcon");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(outputIcon->sizePolicy().hasHeightForWidth());
        outputIcon->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(outputIcon, 1, 2, 2, 2);

        reverse = new QCheckBox(groupBox);
        reverse->setObjectName("reverse");

        gridLayout->addWidget(reverse, 2, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(0, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 4);


        horizontalLayout->addWidget(groupBox);

        tabs->addTab(copiesTab, QString());
        optionsTab = new QWidget();
        optionsTab->setObjectName("optionsTab");
        gridLayout_2 = new QGridLayout(optionsTab);
        gridLayout_2->setObjectName("gridLayout_2");
        colorMode = new QGroupBox(optionsTab);
        colorMode->setObjectName("colorMode");
        gridLayout_4 = new QGridLayout(colorMode);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalSpacer_6 = new QSpacerItem(1, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_6, 2, 0, 1, 1);

        color = new QRadioButton(colorMode);
        color->setObjectName("color");

        gridLayout_4->addWidget(color, 0, 0, 1, 1);

        colorIcon = new QLabel(colorMode);
        colorIcon->setObjectName("colorIcon");

        gridLayout_4->addWidget(colorIcon, 0, 1, 3, 1);

        grayscale = new QRadioButton(colorMode);
        grayscale->setObjectName("grayscale");

        gridLayout_4->addWidget(grayscale, 1, 0, 1, 1);


        gridLayout_2->addWidget(colorMode, 0, 1, 1, 1);

        duplex = new QGroupBox(optionsTab);
        duplex->setObjectName("duplex");
        verticalLayout = new QVBoxLayout(duplex);
        verticalLayout->setObjectName("verticalLayout");
        noDuplex = new QRadioButton(duplex);
        noDuplex->setObjectName("noDuplex");
        noDuplex->setChecked(true);

        verticalLayout->addWidget(noDuplex);

        duplexLong = new QRadioButton(duplex);
        duplexLong->setObjectName("duplexLong");

        verticalLayout->addWidget(duplexLong);

        duplexShort = new QRadioButton(duplex);
        duplexShort->setObjectName("duplexShort");

        verticalLayout->addWidget(duplexShort);

        verticalSpacer_42 = new QSpacerItem(1, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_42);


        gridLayout_2->addWidget(duplex, 0, 0, 1, 1);

        tabs->addTab(optionsTab, QString());

        horizontalLayout_2->addWidget(tabs);

#if QT_CONFIG(shortcut)
        label->setBuddy(copies);
#endif // QT_CONFIG(shortcut)

        retranslateUi(QPrintSettingsOutput);
        QObject::connect(printRange, &QRadioButton::toggled, from, &QSpinBox::setEnabled);
        QObject::connect(printRange, &QRadioButton::toggled, to, &QSpinBox::setEnabled);
        QObject::connect(pagesRadioButton, &QRadioButton::toggled, pagesLineEdit, &QLineEdit::setEnabled);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QPrintSettingsOutput);
    } // setupUi

    void retranslateUi(QWidget *QPrintSettingsOutput)
    {
        QPrintSettingsOutput->setWindowTitle(QCoreApplication::translate("QPrintSettingsOutput", "Form", nullptr));
        gbPrintRange->setTitle(QCoreApplication::translate("QPrintSettingsOutput", "Print range", nullptr));
        printAll->setText(QCoreApplication::translate("QPrintSettingsOutput", "Print all", nullptr));
        printRange->setText(QCoreApplication::translate("QPrintSettingsOutput", "Pages from", nullptr));
        label_3->setText(QCoreApplication::translate("QPrintSettingsOutput", "to", nullptr));
        pagesRadioButton->setText(QCoreApplication::translate("QPrintSettingsOutput", "Pages", nullptr));
#if QT_CONFIG(tooltip)
        pagesLineEdit->setToolTip(QCoreApplication::translate("QPrintSettingsOutput", "Specify pages or ranges separated by commas. Ranges are specified by two numbers separated by a hyphen. E.g: 3,5-7,9 prints pages 3, 5, 6, 7 and 9.", nullptr));
#endif // QT_CONFIG(tooltip)
        printCurrentPage->setText(QCoreApplication::translate("QPrintSettingsOutput", "Current Page", nullptr));
        printSelection->setText(QCoreApplication::translate("QPrintSettingsOutput", "Selection", nullptr));
        pageSetLabel->setText(QCoreApplication::translate("QPrintSettingsOutput", "Page Set:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QPrintSettingsOutput", "Output Settings", nullptr));
        label->setText(QCoreApplication::translate("QPrintSettingsOutput", "Copies:", nullptr));
        collate->setText(QCoreApplication::translate("QPrintSettingsOutput", "Collate", nullptr));
        reverse->setText(QCoreApplication::translate("QPrintSettingsOutput", "Reverse", nullptr));
        tabs->setTabText(tabs->indexOf(copiesTab), QCoreApplication::translate("QPrintSettingsOutput", "Copies", nullptr));
        colorMode->setTitle(QCoreApplication::translate("QPrintSettingsOutput", "Color Mode", nullptr));
        color->setText(QCoreApplication::translate("QPrintSettingsOutput", "Color", nullptr));
        grayscale->setText(QCoreApplication::translate("QPrintSettingsOutput", "Grayscale", nullptr));
        duplex->setTitle(QCoreApplication::translate("QPrintSettingsOutput", "Double Sided Printing", nullptr));
        noDuplex->setText(QCoreApplication::translate("QPrintSettingsOutput", "Off", nullptr));
        duplexLong->setText(QCoreApplication::translate("QPrintSettingsOutput", "Long side binding", nullptr));
        duplexShort->setText(QCoreApplication::translate("QPrintSettingsOutput", "Short side binding", nullptr));
        tabs->setTabText(tabs->indexOf(optionsTab), QCoreApplication::translate("QPrintSettingsOutput", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QPrintSettingsOutput: public Ui_QPrintSettingsOutput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPRINTSETTINGSOUTPUT_H
