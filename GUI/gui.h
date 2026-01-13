#pragma once
//#include "iostream"
//#include "fstream"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtWidgets"
#include "QFileDialog"
#include "CLI/CLI.hpp"

class Ui_MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
        void ButtonClicked();
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    static bool* run;
    static bool* train;
    static bool* debug;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setFixedSize(270, 340);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
//        verticalLayoutWidget->setGeometry(QRect(240, 40, 167, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
//        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName("radioButton");

        gridLayout->addWidget(radioButton, 0, 1, 1, 1);

        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName("radioButton_2");

        gridLayout->addWidget(radioButton_2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        connect(pushButton, &QPushButton::clicked, this, &Ui_MainWindow::ButtonClicked);

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
//        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Искусственный интеллект", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Поле ввода:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Текстовый запрос", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ссылка на промпт", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Выполнить", nullptr));
    } // retranslateUi

};
