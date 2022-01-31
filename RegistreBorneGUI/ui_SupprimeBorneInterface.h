/********************************************************************************
** Form generated from reading UI file 'SupprimeBorneInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMEBORNEINTERFACE_H
#define UI_SUPPRIMEBORNEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SupprimeBorneInterface
{
public:
    QPushButton *btnSupprimer;
    QSpinBox *txtIdentifiant;
    QLabel *lbIdentifiant;

    void setupUi(QDialog *SupprimeBorneInterface)
    {
        if (SupprimeBorneInterface->objectName().isEmpty())
            SupprimeBorneInterface->setObjectName(QString::fromUtf8("SupprimeBorneInterface"));
        SupprimeBorneInterface->resize(564, 131);
        btnSupprimer = new QPushButton(SupprimeBorneInterface);
        btnSupprimer->setObjectName(QString::fromUtf8("btnSupprimer"));
        btnSupprimer->setGeometry(QRect(160, 80, 201, 28));
        txtIdentifiant = new QSpinBox(SupprimeBorneInterface);
        txtIdentifiant->setObjectName(QString::fromUtf8("txtIdentifiant"));
        txtIdentifiant->setGeometry(QRect(250, 20, 281, 31));
        txtIdentifiant->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        txtIdentifiant->setMinimum(1);
        txtIdentifiant->setMaximum(1000000000);
        lbIdentifiant = new QLabel(SupprimeBorneInterface);
        lbIdentifiant->setObjectName(QString::fromUtf8("lbIdentifiant"));
        lbIdentifiant->setGeometry(QRect(40, 20, 201, 31));
        lbIdentifiant->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        retranslateUi(SupprimeBorneInterface);
        QObject::connect(btnSupprimer, SIGNAL(clicked()), SupprimeBorneInterface, SLOT(validerIdentifiant()));

        QMetaObject::connectSlotsByName(SupprimeBorneInterface);
    } // setupUi

    void retranslateUi(QDialog *SupprimeBorneInterface)
    {
        SupprimeBorneInterface->setWindowTitle(QApplication::translate("SupprimeBorneInterface", "SupprimeBorneInterface", nullptr));
        btnSupprimer->setText(QApplication::translate("SupprimeBorneInterface", "Supprimer", nullptr));
        lbIdentifiant->setText(QApplication::translate("SupprimeBorneInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Identifiant de la borne </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimeBorneInterface: public Ui_SupprimeBorneInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMEBORNEINTERFACE_H
