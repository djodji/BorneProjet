/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   RegistreBorneGUI.cpp
 * Author: etudiant
 *
 * Created on 17 avril 2021, 16:39
 */

#include "RegistreBorneGUI.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "AjouterBorneFontaineInterface.h"
#include "AjouterBorneStationnementInterface.h"
#include "BorneException.h"

#include "SupprimeBorneInterface.h"
#include <qfile.h>
#include <qtextstream.h>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <QMessageBox>
#include <QWidget>

RegistreBorneGUI::RegistreBorneGUI (QWidget *parent)
: QMainWindow (parent)
{
  ui.setupUi (this);
  m_RegistreBorne = new RegistreBorne ("bornes de la ville de Québec 2021");
}

void
RegistreBorneGUI::ajouterBorneFontaine (int p_identifiant, const string& p_direction,
                                        const string& p_nomTopographique, const double p_longitude,
                                        const double p_latitude, const string& p_ville, const string& p_arrondissement)
{
  try
    {
      BorneFontaine objetBorne = BorneFontaine (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude, p_ville, p_arrondissement);
      m_RegistreBorne->ajouteBorne (objetBorne);

    }

  catch (BorneDejaPresenteException & e)
    {
      QString message = (e.what ());
      QMessageBox::information (this, "ERREUR", message);

    }
}

void
RegistreBorneGUI::ajouterBorneStationnement (const int p_identifiant, const string& p_direction,
                                             const string& p_nomTopographique, const double p_longitude,
                                             const double p_latitude, const string& p_type, const double p_lectureMetrique,
                                             const int p_segmentRue, const int p_numBorne, const string& p_coteRue)
{
  try
    {
      BorneStationnement borneStationnement (p_identifiant, p_direction, p_nomTopographique, p_longitude,
                                             p_latitude, p_type, p_lectureMetrique, p_segmentRue, p_numBorne, p_coteRue);
      m_RegistreBorne->ajouteBorne (borneStationnement);
    }
  catch (BorneDejaPresenteException & e)
    {
      QString message = (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}

void
RegistreBorneGUI::supprimerBorne (int p_identifiant)
{

  try
    {
      m_RegistreBorne->supprimeBorne (p_identifiant);
    }
  catch (BorneAbsenteException& e)
    {
      QString message = (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}

void
RegistreBorneGUI::dialogAjouterBorneFontaine ()
{
  AjouterBorneFontaineInterface saisieBorneFontaine;
  if (saisieBorneFontaine.exec ())
    {
      ajouterBorneFontaine (saisieBorneFontaine.reqIdentifiant (),
                            saisieBorneFontaine.reqDirection ().toStdString (),
                            saisieBorneFontaine.reqNomTopographique ().toStdString (),
                            saisieBorneFontaine.reqLongitude (),
                            saisieBorneFontaine.reqLatitude (),
                            saisieBorneFontaine.reqVille ().toStdString (),
                            saisieBorneFontaine.reqArrondissement ().toStdString ());
      ui.textBrowser->setPlainText (QString::fromStdString (m_RegistreBorne->reqRegistreBorneFormate ()));
    }
}

void
RegistreBorneGUI::dialogAjouterBorneStationnement ()
{
  AjouterBorneStationnementInterface saisieBorneStationnement;
  if (saisieBorneStationnement.exec ())
    {
      ajouterBorneStationnement (saisieBorneStationnement.reqIdentifiant (),
                                 saisieBorneStationnement.reqDirection ().toStdString (),
                                 saisieBorneStationnement.reqNomTopographique ().toStdString (),
                                 saisieBorneStationnement.reqLongitude (),
                                 saisieBorneStationnement.reqLatitude (),
                                 saisieBorneStationnement.reqType ().toStdString (),
                                 saisieBorneStationnement.reqLectureMetrique (),
                                 saisieBorneStationnement.reqSegmentRue (),
                                 saisieBorneStationnement.reqNumBorne (),
                                 saisieBorneStationnement.reqCoteRue ().toStdString ()
                                 );
      ui.textBrowser->setPlainText (QString::fromStdString (m_RegistreBorne->reqRegistreBorneFormate ()));
    }
}

void
RegistreBorneGUI::dialogSupprimerBorne ()
{
  SupprimeBorneInterface saisieBorne;
  if (saisieBorne.exec ())
    {
      supprimerBorne (saisieBorne.reqIdentifiant ());
    }
  ui.textBrowser->setPlainText (QString::fromStdString (m_RegistreBorne->reqRegistreBorneFormate ()));
}

RegistreBorneGUI::~RegistreBorneGUI () { }
