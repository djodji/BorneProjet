/********************************************************************************
** Form generated from reading UI file 'AjouterBorneFontaineInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERBORNEFONTAINEINTERFACE_H
#define UI_AJOUTERBORNEFONTAINEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjouterBorneFontaineInterface
{
public:
    QLabel *lbDirection;
    QLabel *lbVille;
    QLabel *lbArrondissement;
    QLabel *lbLatitude;
    QLabel *lbNomTopo;
    QLabel *lbLongitude;
    QLabel *lbIdentifiant;
    QSpinBox *txtIdentifiant;
    QComboBox *comboDirection;
    QLineEdit *txtNomTopo;
    QDoubleSpinBox *txtLongitude;
    QDoubleSpinBox *txtLatitude;
    QLineEdit *txtVille;
    QLineEdit *txtArrondissement;
    QPushButton *btnSoumettre;

    void setupUi(QDialog *AjouterBorneFontaineInterface)
    {
        if (AjouterBorneFontaineInterface->objectName().isEmpty())
            AjouterBorneFontaineInterface->setObjectName(QString::fromUtf8("AjouterBorneFontaineInterface"));
        AjouterBorneFontaineInterface->resize(482, 330);
        lbDirection = new QLabel(AjouterBorneFontaineInterface);
        lbDirection->setObjectName(QString::fromUtf8("lbDirection"));
        lbDirection->setGeometry(QRect(10, 50, 171, 31));
        lbVille = new QLabel(AjouterBorneFontaineInterface);
        lbVille->setObjectName(QString::fromUtf8("lbVille"));
        lbVille->setGeometry(QRect(10, 210, 171, 31));
        lbArrondissement = new QLabel(AjouterBorneFontaineInterface);
        lbArrondissement->setObjectName(QString::fromUtf8("lbArrondissement"));
        lbArrondissement->setGeometry(QRect(10, 250, 171, 31));
        lbLatitude = new QLabel(AjouterBorneFontaineInterface);
        lbLatitude->setObjectName(QString::fromUtf8("lbLatitude"));
        lbLatitude->setGeometry(QRect(10, 170, 171, 31));
        lbNomTopo = new QLabel(AjouterBorneFontaineInterface);
        lbNomTopo->setObjectName(QString::fromUtf8("lbNomTopo"));
        lbNomTopo->setGeometry(QRect(10, 90, 171, 31));
        lbLongitude = new QLabel(AjouterBorneFontaineInterface);
        lbLongitude->setObjectName(QString::fromUtf8("lbLongitude"));
        lbLongitude->setGeometry(QRect(10, 130, 171, 31));
        lbIdentifiant = new QLabel(AjouterBorneFontaineInterface);
        lbIdentifiant->setObjectName(QString::fromUtf8("lbIdentifiant"));
        lbIdentifiant->setGeometry(QRect(10, 10, 171, 31));
        txtIdentifiant = new QSpinBox(AjouterBorneFontaineInterface);
        txtIdentifiant->setObjectName(QString::fromUtf8("txtIdentifiant"));
        txtIdentifiant->setGeometry(QRect(200, 10, 271, 28));
        txtIdentifiant->setMinimum(1);
        txtIdentifiant->setMaximum(1000000000);
        comboDirection = new QComboBox(AjouterBorneFontaineInterface);
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->setObjectName(QString::fromUtf8("comboDirection"));
        comboDirection->setGeometry(QRect(200, 50, 271, 28));
        txtNomTopo = new QLineEdit(AjouterBorneFontaineInterface);
        txtNomTopo->setObjectName(QString::fromUtf8("txtNomTopo"));
        txtNomTopo->setGeometry(QRect(200, 90, 271, 28));
        txtLongitude = new QDoubleSpinBox(AjouterBorneFontaineInterface);
        txtLongitude->setObjectName(QString::fromUtf8("txtLongitude"));
        txtLongitude->setGeometry(QRect(200, 130, 271, 28));
        txtLongitude->setDecimals(6);
        txtLongitude->setMaximum(100000000000000.000000000000000);
        txtLatitude = new QDoubleSpinBox(AjouterBorneFontaineInterface);
        txtLatitude->setObjectName(QString::fromUtf8("txtLatitude"));
        txtLatitude->setGeometry(QRect(200, 170, 271, 28));
        txtLatitude->setDecimals(6);
        txtLatitude->setMaximum(10000000000.000000000000000);
        txtVille = new QLineEdit(AjouterBorneFontaineInterface);
        txtVille->setObjectName(QString::fromUtf8("txtVille"));
        txtVille->setGeometry(QRect(200, 210, 271, 28));
        txtArrondissement = new QLineEdit(AjouterBorneFontaineInterface);
        txtArrondissement->setObjectName(QString::fromUtf8("txtArrondissement"));
        txtArrondissement->setGeometry(QRect(200, 250, 271, 28));
        btnSoumettre = new QPushButton(AjouterBorneFontaineInterface);
        btnSoumettre->setObjectName(QString::fromUtf8("btnSoumettre"));
        btnSoumettre->setGeometry(QRect(100, 290, 191, 28));
        QFont font;
        font.setPointSize(12);
        btnSoumettre->setFont(font);

        retranslateUi(AjouterBorneFontaineInterface);
        QObject::connect(btnSoumettre, SIGNAL(clicked()), AjouterBorneFontaineInterface, SLOT(validerChamps()));

        QMetaObject::connectSlotsByName(AjouterBorneFontaineInterface);
    } // setupUi

    void retranslateUi(QDialog *AjouterBorneFontaineInterface)
    {
        AjouterBorneFontaineInterface->setWindowTitle(QApplication::translate("AjouterBorneFontaineInterface", "AjouterBorneFontaineInterface", nullptr));
        lbDirection->setText(QApplication::translate("AjouterBorneFontaineInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Direction</span></p></body></html>", nullptr));
        lbVille->setText(QApplication::translate("AjouterBorneFontaineInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Ville</span></p></body></html>", nullptr));
        lbArrondissement->setText(QApplication::translate("AjouterBorneFontaineInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Arrondissement</span></p></body></html>", nullptr));
        lbLatitude->setText(QApplication::translate("AjouterBorneFontaineInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Latitude</span></p></body></html>", nullptr));
        lbNomTopo->setText(QApplication::translate("AjouterBorneFontaineInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Nom topographique</span></p></body></html>", nullptr));
        lbLongitude->setText(QApplication::translate("AjouterBorneFontaineInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Longitude</span></p></body></html>", nullptr));
        lbIdentifiant->setText(QApplication::translate("AjouterBorneFontaineInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Identifiant de la borne</span></p></body></html>", nullptr));
        comboDirection->setItemText(0, QString());
        comboDirection->setItemText(1, QApplication::translate("AjouterBorneFontaineInterface", "Nord", nullptr));
        comboDirection->setItemText(2, QApplication::translate("AjouterBorneFontaineInterface", "Sud", nullptr));
        comboDirection->setItemText(3, QApplication::translate("AjouterBorneFontaineInterface", "Est", nullptr));
        comboDirection->setItemText(4, QApplication::translate("AjouterBorneFontaineInterface", "Ouest", nullptr));
        comboDirection->setItemText(5, QApplication::translate("AjouterBorneFontaineInterface", "null", nullptr));

        btnSoumettre->setText(QApplication::translate("AjouterBorneFontaineInterface", "Soumettre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterBorneFontaineInterface: public Ui_AjouterBorneFontaineInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERBORNEFONTAINEINTERFACE_H
