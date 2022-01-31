/********************************************************************************
** Form generated from reading UI file 'AjouterBorneStationnementInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERBORNESTATIONNEMENTINTERFACE_H
#define UI_AJOUTERBORNESTATIONNEMENTINTERFACE_H

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

class Ui_AjouterBorneStationnementInterface
{
public:
    QLabel *lbIdentifiant;
    QSpinBox *txtIdentifiant;
    QLabel *lbDirection;
    QLabel *lbNomTopo;
    QLabel *lbLongitude;
    QLabel *lbLatitude;
    QComboBox *comboDirection;
    QLabel *lbType;
    QLabel *lbDistance;
    QLabel *lbNumBorne;
    QLabel *lbSegment;
    QLabel *lbCote;
    QLineEdit *txtNomTopo;
    QDoubleSpinBox *txtLongitude;
    QDoubleSpinBox *txtLatitude;
    QComboBox *comboType;
    QDoubleSpinBox *txtDistance;
    QSpinBox *txtSegment;
    QSpinBox *txtNumBorne;
    QComboBox *comboCote;
    QPushButton *btnSoumettre;

    void setupUi(QDialog *AjouterBorneStationnementInterface)
    {
        if (AjouterBorneStationnementInterface->objectName().isEmpty())
            AjouterBorneStationnementInterface->setObjectName(QString::fromUtf8("AjouterBorneStationnementInterface"));
        AjouterBorneStationnementInterface->resize(485, 463);
        lbIdentifiant = new QLabel(AjouterBorneStationnementInterface);
        lbIdentifiant->setObjectName(QString::fromUtf8("lbIdentifiant"));
        lbIdentifiant->setGeometry(QRect(10, 20, 171, 31));
        txtIdentifiant = new QSpinBox(AjouterBorneStationnementInterface);
        txtIdentifiant->setObjectName(QString::fromUtf8("txtIdentifiant"));
        txtIdentifiant->setGeometry(QRect(200, 20, 271, 28));
        txtIdentifiant->setMinimum(1);
        txtIdentifiant->setMaximum(1000000000);
        lbDirection = new QLabel(AjouterBorneStationnementInterface);
        lbDirection->setObjectName(QString::fromUtf8("lbDirection"));
        lbDirection->setGeometry(QRect(10, 60, 171, 31));
        lbNomTopo = new QLabel(AjouterBorneStationnementInterface);
        lbNomTopo->setObjectName(QString::fromUtf8("lbNomTopo"));
        lbNomTopo->setGeometry(QRect(10, 100, 171, 31));
        lbLongitude = new QLabel(AjouterBorneStationnementInterface);
        lbLongitude->setObjectName(QString::fromUtf8("lbLongitude"));
        lbLongitude->setGeometry(QRect(10, 140, 171, 31));
        lbLatitude = new QLabel(AjouterBorneStationnementInterface);
        lbLatitude->setObjectName(QString::fromUtf8("lbLatitude"));
        lbLatitude->setGeometry(QRect(10, 180, 171, 31));
        comboDirection = new QComboBox(AjouterBorneStationnementInterface);
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->addItem(QString());
        comboDirection->setObjectName(QString::fromUtf8("comboDirection"));
        comboDirection->setGeometry(QRect(200, 60, 271, 28));
        lbType = new QLabel(AjouterBorneStationnementInterface);
        lbType->setObjectName(QString::fromUtf8("lbType"));
        lbType->setGeometry(QRect(10, 220, 171, 31));
        lbDistance = new QLabel(AjouterBorneStationnementInterface);
        lbDistance->setObjectName(QString::fromUtf8("lbDistance"));
        lbDistance->setGeometry(QRect(10, 260, 171, 31));
        lbNumBorne = new QLabel(AjouterBorneStationnementInterface);
        lbNumBorne->setObjectName(QString::fromUtf8("lbNumBorne"));
        lbNumBorne->setGeometry(QRect(10, 340, 171, 31));
        lbSegment = new QLabel(AjouterBorneStationnementInterface);
        lbSegment->setObjectName(QString::fromUtf8("lbSegment"));
        lbSegment->setGeometry(QRect(10, 300, 171, 31));
        lbCote = new QLabel(AjouterBorneStationnementInterface);
        lbCote->setObjectName(QString::fromUtf8("lbCote"));
        lbCote->setGeometry(QRect(10, 380, 171, 31));
        txtNomTopo = new QLineEdit(AjouterBorneStationnementInterface);
        txtNomTopo->setObjectName(QString::fromUtf8("txtNomTopo"));
        txtNomTopo->setGeometry(QRect(200, 100, 271, 28));
        txtLongitude = new QDoubleSpinBox(AjouterBorneStationnementInterface);
        txtLongitude->setObjectName(QString::fromUtf8("txtLongitude"));
        txtLongitude->setGeometry(QRect(200, 140, 271, 28));
        txtLongitude->setDecimals(6);
        txtLongitude->setMaximum(1000000000000.000000000000000);
        txtLatitude = new QDoubleSpinBox(AjouterBorneStationnementInterface);
        txtLatitude->setObjectName(QString::fromUtf8("txtLatitude"));
        txtLatitude->setGeometry(QRect(200, 180, 271, 28));
        txtLatitude->setDecimals(6);
        txtLatitude->setMaximum(1000000000000.000000000000000);
        comboType = new QComboBox(AjouterBorneStationnementInterface);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName(QString::fromUtf8("comboType"));
        comboType->setGeometry(QRect(200, 220, 271, 28));
        txtDistance = new QDoubleSpinBox(AjouterBorneStationnementInterface);
        txtDistance->setObjectName(QString::fromUtf8("txtDistance"));
        txtDistance->setGeometry(QRect(200, 260, 271, 28));
        txtDistance->setDecimals(6);
        txtDistance->setMaximum(10000000000.000000000000000);
        txtSegment = new QSpinBox(AjouterBorneStationnementInterface);
        txtSegment->setObjectName(QString::fromUtf8("txtSegment"));
        txtSegment->setGeometry(QRect(200, 300, 271, 28));
        txtSegment->setMinimum(1);
        txtSegment->setMaximum(1000000000);
        txtNumBorne = new QSpinBox(AjouterBorneStationnementInterface);
        txtNumBorne->setObjectName(QString::fromUtf8("txtNumBorne"));
        txtNumBorne->setGeometry(QRect(200, 340, 271, 28));
        txtNumBorne->setMinimum(1);
        txtNumBorne->setMaximum(9999);
        comboCote = new QComboBox(AjouterBorneStationnementInterface);
        comboCote->addItem(QString());
        comboCote->addItem(QString());
        comboCote->addItem(QString());
        comboCote->addItem(QString());
        comboCote->addItem(QString());
        comboCote->addItem(QString());
        comboCote->setObjectName(QString::fromUtf8("comboCote"));
        comboCote->setGeometry(QRect(200, 380, 271, 28));
        btnSoumettre = new QPushButton(AjouterBorneStationnementInterface);
        btnSoumettre->setObjectName(QString::fromUtf8("btnSoumettre"));
        btnSoumettre->setGeometry(QRect(100, 420, 211, 30));
        QFont font;
        font.setPointSize(12);
        btnSoumettre->setFont(font);

        retranslateUi(AjouterBorneStationnementInterface);
        QObject::connect(btnSoumettre, SIGNAL(clicked()), AjouterBorneStationnementInterface, SLOT(validerChamps()));

        QMetaObject::connectSlotsByName(AjouterBorneStationnementInterface);
    } // setupUi

    void retranslateUi(QDialog *AjouterBorneStationnementInterface)
    {
        AjouterBorneStationnementInterface->setWindowTitle(QApplication::translate("AjouterBorneStationnementInterface", "Ajouter Borne de Stationnement ", nullptr));
        lbIdentifiant->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Identifiant de la borne</span></p></body></html>", nullptr));
        lbDirection->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Direction</span></p></body></html>", nullptr));
        lbNomTopo->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Nom topographique</span></p></body></html>", nullptr));
        lbLongitude->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Longitude</span></p></body></html>", nullptr));
        lbLatitude->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Latitude</span></p></body></html>", nullptr));
        comboDirection->setItemText(0, QString());
        comboDirection->setItemText(1, QApplication::translate("AjouterBorneStationnementInterface", "Nord", nullptr));
        comboDirection->setItemText(2, QApplication::translate("AjouterBorneStationnementInterface", "Sud", nullptr));
        comboDirection->setItemText(3, QApplication::translate("AjouterBorneStationnementInterface", "Est", nullptr));
        comboDirection->setItemText(4, QApplication::translate("AjouterBorneStationnementInterface", "Ouest", nullptr));
        comboDirection->setItemText(5, QApplication::translate("AjouterBorneStationnementInterface", "null", nullptr));

        lbType->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Type</span></p></body></html>", nullptr));
        lbDistance->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Distance mesuree</span></p></body></html>", nullptr));
        lbNumBorne->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Num\303\251ro de la borne</span></p></body></html>", nullptr));
        lbSegment->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Segment de rue</span></p></body></html>", nullptr));
        lbCote->setText(QApplication::translate("AjouterBorneStationnementInterface", "<html><head/><body><p><span style=\" font-size:12pt;\">Cote de la rue</span></p></body></html>", nullptr));
        comboType->setItemText(0, QApplication::translate("AjouterBorneStationnementInterface", "stationnement", nullptr));
        comboType->setItemText(1, QApplication::translate("AjouterBorneStationnementInterface", "paiement", nullptr));

        comboCote->setItemText(0, QString());
        comboCote->setItemText(1, QApplication::translate("AjouterBorneStationnementInterface", "Nord", nullptr));
        comboCote->setItemText(2, QApplication::translate("AjouterBorneStationnementInterface", "Sud", nullptr));
        comboCote->setItemText(3, QApplication::translate("AjouterBorneStationnementInterface", "Est", nullptr));
        comboCote->setItemText(4, QApplication::translate("AjouterBorneStationnementInterface", "Ouest", nullptr));
        comboCote->setItemText(5, QApplication::translate("AjouterBorneStationnementInterface", "null", nullptr));

        btnSoumettre->setText(QApplication::translate("AjouterBorneStationnementInterface", "Soumettre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterBorneStationnementInterface: public Ui_AjouterBorneStationnementInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERBORNESTATIONNEMENTINTERFACE_H
