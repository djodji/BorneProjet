/********************************************************************************
** Form generated from reading UI file 'RegistreBorneGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTREBORNEGUI_H
#define UI_REGISTREBORNEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistreBorneGUI
{
public:
    QAction *actionSupprimer;
    QAction *actionBorneFontaine;
    QAction *actionBorneStationnement;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjpouter_borne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegistreBorneGUI)
    {
        if (RegistreBorneGUI->objectName().isEmpty())
            RegistreBorneGUI->setObjectName(QString::fromUtf8("RegistreBorneGUI"));
        RegistreBorneGUI->setEnabled(true);
        RegistreBorneGUI->resize(844, 912);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        RegistreBorneGUI->setFont(font);
        actionSupprimer = new QAction(RegistreBorneGUI);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionBorneFontaine = new QAction(RegistreBorneGUI);
        actionBorneFontaine->setObjectName(QString::fromUtf8("actionBorneFontaine"));
        actionBorneStationnement = new QAction(RegistreBorneGUI);
        actionBorneStationnement->setObjectName(QString::fromUtf8("actionBorneStationnement"));
        actionQuitter = new QAction(RegistreBorneGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(RegistreBorneGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 20, 791, 851));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Mono L"));
        textBrowser->setFont(font1);
        textBrowser->setLineWidth(1);
        RegistreBorneGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegistreBorneGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 844, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjpouter_borne = new QMenu(menuMenu);
        menuAjpouter_borne->setObjectName(QString::fromUtf8("menuAjpouter_borne"));
        RegistreBorneGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(RegistreBorneGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RegistreBorneGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjpouter_borne->menuAction());
        menuMenu->addAction(actionSupprimer);
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuitter);
        menuAjpouter_borne->addAction(actionBorneFontaine);
        menuAjpouter_borne->addAction(actionBorneStationnement);

        retranslateUi(RegistreBorneGUI);
        QObject::connect(actionQuitter, SIGNAL(triggered()), RegistreBorneGUI, SLOT(close()));
        QObject::connect(actionBorneFontaine, SIGNAL(triggered()), RegistreBorneGUI, SLOT(dialogAjouterBorneFontaine()));
        QObject::connect(actionSupprimer, SIGNAL(triggered()), RegistreBorneGUI, SLOT(dialogSupprimerBorne()));
        QObject::connect(actionBorneStationnement, SIGNAL(triggered()), RegistreBorneGUI, SLOT(dialogAjouterBorneStationnement()));

        QMetaObject::connectSlotsByName(RegistreBorneGUI);
    } // setupUi

    void retranslateUi(QMainWindow *RegistreBorneGUI)
    {
        RegistreBorneGUI->setWindowTitle(QApplication::translate("RegistreBorneGUI", "Gestion des Bornes", nullptr));
        actionSupprimer->setText(QApplication::translate("RegistreBorneGUI", "Supprimer", nullptr));
        actionBorneFontaine->setText(QApplication::translate("RegistreBorneGUI", "BorneFontaine", nullptr));
        actionBorneStationnement->setText(QApplication::translate("RegistreBorneGUI", "BorneStationnement", nullptr));
        actionQuitter->setText(QApplication::translate("RegistreBorneGUI", "Quitter", nullptr));
        textBrowser->setDocumentTitle(QApplication::translate("RegistreBorneGUI", "Registre des Bornes", nullptr));
        textBrowser->setHtml(QApplication::translate("RegistreBorneGUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><title>Registre des Bornes</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Nimbus Mono L'; font-size:10pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier'; font-weight:400;\"><br /></p></body></html>", nullptr));
        menuMenu->setTitle(QApplication::translate("RegistreBorneGUI", "Menu", nullptr));
        menuAjpouter_borne->setTitle(QApplication::translate("RegistreBorneGUI", "Ajpouter borne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistreBorneGUI: public Ui_RegistreBorneGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTREBORNEGUI_H
