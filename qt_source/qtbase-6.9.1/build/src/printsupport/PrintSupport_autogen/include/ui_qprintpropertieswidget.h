/********************************************************************************
** Form generated from reading UI file 'qprintpropertieswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPRINTPROPERTIESWIDGET_H
#define UI_QPRINTPROPERTIESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qpagesetupdialog_unix_p.h"

QT_BEGIN_NAMESPACE

class Ui_QPrintPropertiesWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabs;
    QWidget *tabPage;
    QHBoxLayout *horizontalLayout;
    QPageSetupWidget *pageSetup;
    QWidget *cupsPropertiesPage;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *conflictsLabel;

    void setupUi(QWidget *QPrintPropertiesWidget)
    {
        if (QPrintPropertiesWidget->objectName().isEmpty())
            QPrintPropertiesWidget->setObjectName("QPrintPropertiesWidget");
        QPrintPropertiesWidget->resize(396, 288);
        verticalLayout_4 = new QVBoxLayout(QPrintPropertiesWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabs = new QTabWidget(QPrintPropertiesWidget);
        tabs->setObjectName("tabs");
        tabPage = new QWidget();
        tabPage->setObjectName("tabPage");
        horizontalLayout = new QHBoxLayout(tabPage);
        horizontalLayout->setObjectName("horizontalLayout");
        pageSetup = new QPageSetupWidget(tabPage);
        pageSetup->setObjectName("pageSetup");

        horizontalLayout->addWidget(pageSetup);

        tabs->addTab(tabPage, QString());
        cupsPropertiesPage = new QWidget();
        cupsPropertiesPage->setObjectName("cupsPropertiesPage");
        verticalLayout_2 = new QVBoxLayout(cupsPropertiesPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea = new QScrollArea(cupsPropertiesPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 376, 217));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        tabs->addTab(cupsPropertiesPage, QString());

        verticalLayout_4->addWidget(tabs);

        conflictsLabel = new QLabel(QPrintPropertiesWidget);
        conflictsLabel->setObjectName("conflictsLabel");
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(165, 167, 169, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush1);
        conflictsLabel->setPalette(palette);

        verticalLayout_4->addWidget(conflictsLabel);


        retranslateUi(QPrintPropertiesWidget);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QPrintPropertiesWidget);
    } // setupUi

    void retranslateUi(QWidget *QPrintPropertiesWidget)
    {
        QPrintPropertiesWidget->setWindowTitle(QCoreApplication::translate("QPrintPropertiesWidget", "Form", nullptr));
        tabs->setTabText(tabs->indexOf(tabPage), QCoreApplication::translate("QPrintPropertiesWidget", "Page", nullptr));
        tabs->setTabText(tabs->indexOf(cupsPropertiesPage), QCoreApplication::translate("QPrintPropertiesWidget", "Advanced", nullptr));
        conflictsLabel->setText(QCoreApplication::translate("QPrintPropertiesWidget", "There are conflicts in some options. Please fix them.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QPrintPropertiesWidget: public Ui_QPrintPropertiesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPRINTPROPERTIESWIDGET_H
